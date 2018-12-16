#include <iostream>
#include <windows.h>
#include <fstream>
#include <chrono>
#include <thread>
#include <mutex>

using namespace std;

mutex mtx;

void count(string &s,int &c, mutex &mtx)
{
    mtx.lock();

    const char path[] = "C:\\Users\\Gennady\\Downloads\\Win32Lab2018\\WinApiLab5\\l5.txt";
    ifstream ifs(path);
    getline(ifs,s);
    ifs.close();

    //cout<<s;
    c = atoi(s.c_str());
    c = (c+1)%10;

    ofstream out(path,ios_base::trunc);
    out<<c;
    out.close();
    //Sleep(100);

    mtx.unlock();
}


int main()
{
    //string s;
    //thread th(count,std::ref(s));
    //cout<<"S;:"<<s;
    system("pause");

    SYSTEMTIME sm;
	GetLocalTime(&sm);

	//cout<<sm.wHour<<":"<<sm.wMinute<<":"<<sm.wSecond<<"\n";//get current time of our system
	//sm.wHour = sm.wHour+1;

	int hour_t , minute_t , second_t = 0;
	minute_t = sm.wMinute+1;
	second_t = sm.wSecond;

	if(sm.wMinute == 50)
        cout<<"OK\n";
    while(true)
    {
        string s; int c=0;
        thread th(count,std::ref(s),std::ref(c),std::ref(mtx));
        thread th2(count,std::ref(s),std::ref(c),std::ref(mtx));
        th.join();
        th2.join();
        system("cls");
        //GetLocalTime(&sm);
        cout<<sm.wHour<<":"<<sm.wMinute<<":"<<sm.wSecond<<"\n";
        Sleep(950);
        if(sm.wSecond < 60)
            sm.wSecond++;
        if(sm.wSecond == 60 && sm.wMinute < 59)
        {
            sm.wSecond = 0;
            sm.wMinute++;
        }
        if(sm.wSecond == 60 && sm.wMinute == 60 && sm.wHour < 24)
        {
            sm.wSecond == 0;
            sm.wMinute == 0;
            sm.wHour++;
        }
        if(sm.wSecond == 60 && sm.wMinute == 60 && sm.wHour == 23)
        {
            sm.wSecond == 0;
            sm.wMinute == 0;
            sm.wHour==0;
        }
        //sm.wMinute = sm.wMinute + minute_t;
        if(sm.wSecond == second_t && sm.wMinute == minute_t)
        {
            cout<<"OK\n";
            cout<<c;
            for(int i=0;i<c;i++)
            {
                //cout<<c;system("pause");
                Beep( 750, 300 );
            }

            //sm.wSecond++;
            GetLocalTime(&sm);
            minute_t++;
        }
        else
        {
            continue;
        }
    }

    return 0;
}
