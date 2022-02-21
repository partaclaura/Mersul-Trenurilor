//biblioteci aferente c
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//biblioteci cpp
#include <iostream>
//biblioteci xml
#include "tinyxml2.cpp"

using namespace std;
using namespace tinyxml2;

#define PORT 2024

extern int errno;

char reply[1000];
char requested_trains[10][1000];
int count_trains;//numara trenurile ce vor fi trimise catre client

void get_XMLdata(const char* id)
{
    XMLDocument doc;
    doc.LoadFile( "sample.xml" );//se acceseaza fisierul XML
    XMLElement * pTop = doc.RootElement();//file

    XMLElement *pElements = pTop->FirstChildElement("Trains");
    XMLElement *pElement = pElements->FirstChildElement("Train");
    while(pElement)//se parcurg trenurile din fisierul XML
    {
        XMLElement *pID = pElement->FirstChildElement("IDtren");
        if(strcmp(id, pID->GetText()) == 0)//atunci cand se gaseste trenul cautat
        {
            count_trains++;
            strcpy(requested_trains[count_trains], pID->GetText());
            strcat(requested_trains[count_trains], ",");

            pID = pElement->FirstChildElement("plecare");
            strcat(requested_trains[count_trains], pID->GetText());
            strcat(requested_trains[count_trains], ",");

            pID = pElement->FirstChildElement("sosire");
            strcat(requested_trains[count_trains], pID->GetText());
            strcat(requested_trains[count_trains], ",");

            pID = pElement->FirstChildElement("statusPlecare");
            strcat(requested_trains[count_trains], pID->GetText());
            strcat(requested_trains[count_trains], ",");

            pID = pElement->FirstChildElement("statusSosire");
            strcat(requested_trains[count_trains], pID->GetText());
            strcat(requested_trains[count_trains], ",");

            pID = pElement->FirstChildElement("intarziere");
            if(pID) strcat(requested_trains[count_trains], pID->GetText());
            else strcat(requested_trains[count_trains], "0");
            strcat(requested_trains[count_trains], ",");

            pID = pElement->FirstChildElement("estim");
            strcat(requested_trains[count_trains], pID->GetText());
            strcat(requested_trains[count_trains], ";");


        }
        pElement = pElement -> NextSiblingElement("Train");//se trece la urmatorul nod 'Tren' din fisier

    }
}

bool searchInXML(char* tosearch, const char* type1, const char* type2, const char* type3)
{

    XMLDocument doc;
    doc.LoadFile( "sample.xml" );//se acceseaza fisierul XML
    XMLElement * pTop = doc.RootElement();//file

    XMLElement *pElements = pTop->FirstChildElement(type1);//trenuri
    XMLElement *pElement = pElements->FirstChildElement(type2);
    while(pElement)//se ia fiecare tren pe rand si se verifica id-ul pana cand se gaseste trenul cautat
    {
        XMLElement *pdata = pElement->FirstChildElement(type3);
        if(strcmp(tosearch, pdata->GetText()) == 0)
        {
            return true;
        }
        pElement = pElement -> NextSiblingElement(type2);

    }
    return false;
}

void addUserToXML(char* username, char* password)
{
    XMLDocument doc;
    if(doc.LoadFile("sample.xml") == XML_SUCCESS)
    {
        XMLElement* rootNode = doc.RootElement();
        XMLElement* mainElement = rootNode->FirstChildElement("Users");
        XMLElement* NewElement = doc.NewElement("User");
        mainElement->InsertEndChild(NewElement);

        XMLElement* Newdata = doc.NewElement("username");
        Newdata->SetText(username);
        NewElement->InsertEndChild(Newdata);

        Newdata = doc.NewElement("password");
        Newdata->SetText(password);
        NewElement->InsertEndChild(Newdata);
        doc.SaveFile("sample.xml");

    }

}

void addUser(char* username, char* password)
{
    //serach if username is valid
    if(searchInXML(username,"Users","User","username") == false)
    {
        addUserToXML(username, password);
        strcpy(reply,"true");
    }
    else{
        //request new sign up info
        cout<<"username already taken!\n";
        strcpy(reply,"false");
    }
}

bool findUser(char* username, char* password)
{
    if(searchInXML(username,"Users","User","username") == true && 
        searchInXML(password,"Users","User","password") == true)
    {
        cout<<"User found->log in\n";
        return true;
    }
    else{
        cout<<"User not found\n";
        return false;
    }
}

void checkDay(char* day)
{
    XMLDocument doc;
    doc.LoadFile( "sample.xml" );//se acceseaza fisierul XML
    XMLElement * pTop = doc.RootElement();//file

    XMLElement *pElements = pTop->FirstChildElement("Trains");
    XMLElement *pElement = pElements->FirstChildElement("Train");
    while(pElement)
    {
        XMLElement *pID = pElement->FirstChildElement("IDtren");
        XMLElement *pDays = pElement->FirstChildElement("zileDisponibil");
        XMLElement *pday = pDays->FirstChildElement("zi");
        while(pday)
        {
            if(strcmp(day, pday->GetText()) == 0)
            {
                get_XMLdata(pID->GetText());
            }
            pday = pday -> NextSiblingElement("zi");
        }
        pElement = pElement -> NextSiblingElement("Train");

    }
}

void trainsToday()
{
	char today[9];
    time_t tt;
    struct tm* ti;
    static const char wday_name[][9] = {
    "Duminica", "Luni", "Marti", "Miercuri", "Joi", "Vineri", "Sambata"
    };

    time(&tt);
    ti = localtime(&tt);

    strcpy(today, wday_name[ti->tm_wday]);

    //cauta trenurile de astazi
    bzero(requested_trains,10);
    count_trains = -1;
    checkDay(today);

}

void checkHour(int hour, int minutes, const char* type)
{
    XMLDocument doc;
    doc.LoadFile( "sample.xml" );//se acceseaza fisierul XML
    XMLElement * pTop = doc.RootElement();//nod file

    XMLElement *pElements = pTop->FirstChildElement("Trains");
    XMLElement *pElement = pElements->FirstChildElement("Train");
    while(pElement)
    {
        XMLElement *pID = pElement->FirstChildElement("IDtren");
        XMLElement *pdata = pElement->FirstChildElement(type);
        char data[6];
        strcpy(data, pdata->GetText());
        int thour = (data[0]-'0')*10 + (data[1]-'0');
        int tmin  = (data[3]-'0')*10 + (data[4]-'0');
        if((thour == hour && tmin >= minutes) || (thour == hour+1 && tmin <= minutes))
        {
            get_XMLdata(pID->GetText());
        }
        pElement = pElement -> NextSiblingElement("Train");

    }
}

void currentDepartures()
{
    //get current hour
    time_t tt;
    struct tm* ti;

    time(&tt);
    ti = localtime(&tt);
    int hour = ti->tm_hour;
    int minutes = ti->tm_min;

    bzero(requested_trains,10);
    count_trains = -1;

    //cout<<"its "<<hour<<" "<<minutes<<'\n';
    checkHour(hour, minutes, "statusPlecare");

}

void currentArrivals()
{
    //get current hour
    time_t tt;
    struct tm* ti;

    time(&tt);
    ti = localtime(&tt);
    int hour = ti->tm_hour;
    int minutes = ti->tm_min;

    bzero(requested_trains,10);
    count_trains = -1;

    //cout<<"its "<<hour<<" "<<minutes<<'\n';
    checkHour(hour, minutes, "statusSosire");

}

int get_digits(int number)
{
    int count = 0;
    while(number)
    {
        count++;
        number = number/10;
    }
    return count;
}

void updateEstim(const char* id, const char* delay)
{
    int minutes;
    minutes = atoi(delay);
    XMLDocument doc;
    if(doc.LoadFile("sample.xml") == XML_SUCCESS)
    {
        //root element Data
        XMLElement* rootNode = doc.RootElement();
        //Train
        XMLElement* trainsNode = rootNode->FirstChildElement("Trains");
        XMLElement* trainNode = trainsNode->FirstChildElement("Train");
        while(trainNode)//se cauta trenul dupa id
        {
            XMLElement *pID = trainNode->FirstChildElement("IDtren");
            if(strcmp(id, pID->GetText()) == 0)//atunci cand se gaseste trenul
            {
                XMLElement *estimNode = trainNode->FirstChildElement("estim");
                XMLElement *pdata =trainNode->FirstChildElement("statusSosire");
                char data[6];
                strcpy(data, pdata->GetText());
                int thour = (data[0]-'0')*10 + (data[1]-'0');
                int tmin  = (data[3]-'0')*10 + (data[4]-'0');
                int dhour = minutes/60;
                int dmin  = minutes%60;
                cout<<thour<<":"<<tmin<<'\n';
                cout<<dhour<<":"<<dmin<<'\n';
                thour = thour + dhour;
                tmin = tmin + dmin;
                thour =  (thour + (tmin/60))%24;
                tmin = tmin%60;

                cout<<thour<<":"<<tmin<<'\n';

                data[0] = thour/10 + '0';
                data[1] = thour%10 + '0';
                data[3] = tmin/10 + '0';
                data[4] = tmin%10 + '0';
                cout<<data<<'\n';

                cout<<estimNode->GetText()<<'\n';
                estimNode->SetText(data);
                cout<<estimNode->GetText()<<'\n';
                //doc.SaveFile("sample.xml");
                
            }
            //doc.SaveFile("sample.xml");
            trainNode = trainNode->NextSiblingElement("Train");
        }
        doc.SaveFile("sample.xml");

    }
    
}

void signalDelay(const char* id, const char* delay)
{
	//se memoreaza intarzierea in minutes (covertita in int)
    int minutes;
    minutes = atoi(delay);
    
    XMLDocument doc;
    if(doc.LoadFile("sample.xml") == XML_SUCCESS)
    {
        //root element Data
        XMLElement* rootNode = doc.RootElement();
        //Train
        XMLElement* trainsNode = rootNode->FirstChildElement("Trains");
        XMLElement* trainNode = trainsNode->FirstChildElement("Train");
        while(trainNode)//se cauta trenul dupa id
        {
            XMLElement *pID = trainNode->FirstChildElement("IDtren");
            if(strcmp(id, pID->GetText()) == 0)//atunci cand se gaseste
            {
                //intarziere, daca nu exista, se adauga, altfel se face update
                XMLElement* delayNode = trainNode->FirstChildElement("intarziere");
                if(delayNode == nullptr)
                {

                    XMLElement* NewElement = doc.NewElement("intarziere");
                    NewElement->SetText(delay);
                    trainNode->InsertEndChild(NewElement);
                    doc.SaveFile("sample.xml");
                    updateEstim(id, delay);
                }
                else{
                    //se extrage intarzierea existenta deja
                    int data = atoi(delayNode->GetText());
                    //se calculeaza media
                    minutes = (minutes+data)/2;
                    char update[6];
                    int digits=get_digits(minutes);
                    update[digits]='\0';
                    while(minutes)
                    {
                        update[digits-1] = minutes%10 + '0';
                        minutes /= 10;
                        digits--;
                    }
                    //si se face update la intarziere
                    delayNode->SetText(update);
                    doc.SaveFile("sample.xml");
                    updateEstim(id, update);
                }

                
            }
            trainNode = trainNode->NextSiblingElement("Train");
        }

    }
}

void getTrains()
{
	for(int i=0; i<=count_trains; i++)//se adauga fiecare tren cerut la mesajul ce se va trimite inapoi clientului
    {
        strcat(reply, requested_trains[i]);
    }
}

void to_send(char* text)
{
	char get_data[3][20];
	char* word = strtok(text,";");
	int i = 0;
	while(word)//se se desparte comanda primita de la client tipComanda;infoDeLaClient;infoDeLaClient
	{
		strcpy(get_data[i], word);
		i++;
		word = strtok(NULL,";");
	}
	//se verifica tipul de comanda primit si se apeleaza functiile corespunzatoare
	if(strcmp(get_data[0],"login") == 0)//login;username;password
	{
		if(findUser(get_data[1], get_data[2]) == true)//daca se contul exista
			strcpy(reply,"true");//se trimite un mesaj corespunzator
		else strcpy(reply,"false");
	}
	else if(strcmp(get_data[0],"signup") == 0)//signup;username;password
	{
		addUser(get_data[1], get_data[2]);
	}
	else if(strcmp(get_data[0], "mersulastazi") == 0)
	{
		trainsToday();
		getTrains();
	}
	else if(strcmp(get_data[0], "sosiri") == 0)
	{
		currentArrivals();
		getTrains();
	}
	else if(strcmp(get_data[0], "plecari") == 0)
	{
		currentDepartures();
		getTrains();
	}
	else if(strcmp(get_data[0], "signaldelay") == 0)
	{
		signalDelay(get_data[1], get_data[2]);//signaldelay;trainID;minutes

	}

}

int main()
{
	struct sockaddr_in server;
	struct sockaddr_in from;
	char msg[1000];
	char msgrasp[1000]=" ";
	int sd;

	if((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		perror("[server]Eroare la socket.\n");
		return errno;
	}

	bzero(&server, sizeof(server));
	bzero(&from, sizeof(from));

	server.sin_family = AF_INET;
	server.sin_addr.s_addr = htonl(INADDR_ANY);
	server.sin_port = htons(PORT);

	if(bind(sd, (struct sockaddr*) &server, sizeof(struct sockaddr)) == -1)
	{
		perror("[server]Eroare la bind.\n");
		return errno;
	}

	if(listen(sd, 1) == -1)
	{
		perror("[server]Eroare la listen.\n");
		return errno;
	}

	while(1)
	{
		int client;
		int length = sizeof(from);

		printf ("[server]Asteptam la portul %d...\n",PORT);
        fflush (stdout);

        client = accept (sd, (struct sockaddr *) &from, &length);

        if (client < 0)
        {
            perror ("[server]Eroare la accept.\n");
            continue;
        }

        int pid;
        if((pid = fork()) == -1){
        	close(client);
        	continue;
        }
        else if(pid > 0)
        {
        	close(client);
        	while(waitpid(-1,NULL,WNOHANG));
        	continue;
        }
        else if(pid == 0)
        {
        	close(sd);

            /* s-a realizat conexiunea, se astepta mesajul */
            bzero (msg, 1000);
            printf ("[server]Asteptam mesajul...\n");
            fflush (stdout);

            /* citirea mesajului */
            if (read (client, msg, 1000) <= 0)
            {
                perror ("[server]Eroare la read() de la client.\n");
                close (client); /* inchidem conexiunea cu clientul */
                continue;       /* continuam sa ascultam */
            }

            printf ("[server]Mesajul a fost receptionat...%s\n", msg);

            /*pregatim mesajul de raspuns */
            bzero(msgrasp,1000);
            to_send(msg);
            strcpy(msgrasp, reply);

            printf("[server]Trimitem mesajul inapoi...%s\n",msgrasp);


            /* returnam mesajul clientului */
            if (write (client, msgrasp, 1000) <= 0)
            {
                perror ("[server]Eroare la write() catre client.\n");
                continue;       /* continuam sa ascultam */
            }
            else
                printf ("[server]Mesajul a fost trasmis cu succes.\n");
            
            /* am terminat cu acest client, inchidem conexiunea */
            close (client);
            exit(0);

        }


	}

}
