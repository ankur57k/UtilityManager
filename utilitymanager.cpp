#include <QtGui/QApplication>
#include "utilitymanager.h"
#include "ui_utilitymanager.h"
#include "ui_taskManager.h"
#include "ui_safe_remove.h"
#include "ui_unmountdisk.h"
#include "qthread.h"
#include "qtimer.h"
#include "stdio.h"
#include "time.h"
#include "string.h"
#include "stdlib.h"
#include "qlistview.h"
#include "math.h"
#include "qpushbutton.h"
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <fnmatch.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "string_Memory.h"
#include <qabstractbutton.h>
#include <qlayout.h>
#include <qradiobutton.h>
#include <qmessagebox.h>
#include <qstring.h>
#include <qlabel.h>
#include <signal.h>
#include <sys/mount.h>
#include <QCloseEvent>

QRadioButton** radioButton;
int totalDisk,totalPid;
char **foundPid=NULL,*selectedMountPoint=NULL;




UtilityManager::UtilityManager(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UtilityManager)
{
    ui->setupUi(this);
}

UtilityManager::~UtilityManager()
{
    delete ui;
}

void UtilityManager::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}






void UtilityManager::on_taskManager_clicked()
{
    TaskManager *w = new TaskManager();

    w->show();
}


void UtilityManager::on_troubleShootDisk_clicked()
{
    int index=0;
     char **value=NULL,*temp=NULL;



     FILE *data = fopen("/proc/mounts","r");


     if(data==NULL)
     {
             perror("Path not valid\n");
     }

     temp = memory_Initialize(temp,0,1);

     int check1=0,count=0;

     while(!feof(data))
     {

             count = 0;

             do
             {
                     count++;
                     fread(temp,sizeof(char),1,data);

                     if((count==1)&&(temp[0]=='g'))
                             check1++;


                     if((count==2)&&(temp[0]=='v'))
                             check1++;


                     if((count==3)&&(temp[0]=='f'))
                             check1++;


                     if((count==4)&&(temp[0]=='s'))
                             check1++;




                     if(check1>4)
                     {
                             int check=0,i=0;

                             value = (char **)realloc(value,(index+1)*sizeof(char *));

                             value[index] = NULL;

                             while(temp[0]!='\n')
                             {
                                     fread(temp,sizeof(char),1,data);

                                     if((check==0)&&(temp[0]==' '))
                                     {

                                                     check = 1;
                                     }
                                     else
                                     {

                                             if((check==1)&&(temp[0]==' '))
                                                     check = 2;
                                             else
                                             {
                                                     if(check==1)
                                                     {
                                                             value[index] = memory_Initialize(value[index],i,(i+1));
                                                             string_Copy(value[index],temp);

                                                             i++;

                                                     }
                                             }
                                     }
                             }

                             index++;
                     }

             }while(temp[0]!='\n');

             if(check1==4)
                     check1++;

     }

     fclose(data);
     data = NULL;

     free(temp);

     int i;







    totalDisk = index-1;




     if(index>1)
     {
        safe_Remove *safe = new safe_Remove();


        radioButton = (QRadioButton **)malloc((index-1)*sizeof(QRadioButton *));

        QGridLayout* grid = new QGridLayout(safe->centralWidget());

        QString str="";

        int j=0;

        if(((index-2)%2)==0)
        {
            j = (index-2)/2;
        }
        else
        {
            j = (index-1)/2;
        }
        for(i=0;i<(index-1);i++)
        {

             str = "";
             str = str + value[i];
             radioButton[i] = new QRadioButton(str,safe->centralWidget());



             radioButton[i]->setCheckable(TRUE);

             grid->addWidget(radioButton[i],i,1);

             if(i==j)
             {
                 QPushButton *button = new QPushButton("Check Safe Remove",safe->centralWidget());
                 grid->addWidget(button,i,2);
                 connect(button, SIGNAL(clicked()), SLOT(on_checkSafeRemove_clicked()));

             }
        }


        for(i=0;i<(index-1);i++)
                     free(value[i]);

        free(value);










        safe->show();

    }
    else
    {

        QMessageBox msgBox;
        msgBox.setText("Mounted drive not found");
        msgBox.exec();
    }




}






















TaskManager::TaskManager(QWidget *parent) :
    QMainWindow(parent),
    task(new Ui::TaskManager)
    {



        task->setupUi(this);
        QTimer *timer = new QTimer(this);



        task->TableWidgetProcess->setRowCount(400);


        QStringList str;
        str<<"Pid"<<"Process Name"<<"Status"<<"Memory Used";
        task->TableWidgetProcess->verticalHeader()->hide();




        task->TableWidgetProcess->setHorizontalHeaderLabels(str);


        connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
        timer->start(1000);
        showTime();







    }


TaskManager::~TaskManager()
{
    delete task;
}


void TaskManager::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        task->retranslateUi(this);
        break;
    default:
        break;
    }
}





void TaskManager::showTime()
{

    int temp=0;  //to control on after how many seconds process listing to update



    showMemInfo();

    showBasicInfo();
    showOsVersion();
    showNetworkInfo();

    if(temp%3==0)
    {

        showProcessInfo();

        temp=0;
    }

    temp++;

    showBatteryInfo();



}






void TaskManager::showProcessInfo()
{
    int index=0,no=0,j=0;
    QString str;
            char *path=NULL,*value[4],*temp=NULL;
            DIR *proc_Dir=NULL;
            struct dirent *pid=NULL;

            for(index=0;index<4;index++)
                    value[index] = NULL;

            proc_Dir = opendir("/proc/");

            temp = memory_Initialize(temp,0,1);

            FILE *data=NULL;
            while((pid=readdir(proc_Dir))!=NULL)
            {
                    if((pid->d_name[0]>47)&&(pid->d_name[0]<58))
                    {
                            no =  0;
                            index = 0;
                            path = memory_Initialize(path,0,(13+strlen(pid->d_name)));
                            string_Copy(path,"/proc/");
                            string_Copy(path,pid->d_name);
                            string_Copy(path,"/status");

                            value[0] = memory_Initialize(value[0],0,strlen(pid->d_name));
                            string_Copy(value[0],pid->d_name);




                            data = fopen(path,"r");

                            free(path);
                            path = NULL;

                            if(data==NULL)
                            {
                                    perror("Path not valid\n");
                            }


                            index++;

                            while(no<2)
                            {
                                    do
                                    {
                                            fread(temp,sizeof(char),1,data);

                                            if((no==0)||(no==1))
                                            {
                                                    int check=0,i=0;

                                                    while(temp[0]!='\n')
                                                    {
                                                            fread(temp,sizeof(char),1,data);

                                                            if(check==0)
                                                            {
                                                                    if(temp[0]==':')
                                                                            check = 1;
                                                            }
                                                            else
                                                            {
                                                                    if((check==1)&&(temp[0]!=32))
                                                                            check = 2;

                                                                    if((check==2)&&(temp[0]!='\n'))
                                                                    {
                                                                            value[index] = memory_Initialize(value[index],i,(i+1));
                                                                            string_Copy(value[index],temp);

                                                                            i++;
                                                                    }

                                                            }

                                                    }

                                                index++;
                                                }

                                    }while(temp[0]!='\n');
                                    no++;
                            }

                            no = 0;


                            fclose(data);
                            data = NULL;


                            path = memory_Initialize(path,0,(13+strlen(pid->d_name)));
                            string_Copy(path,"/proc/");
                            string_Copy(path,pid->d_name);
                            string_Copy(path,"/statm");

                            data = fopen(path,"r");

                            free(path);
                            path = NULL;

                            while(no<2)
                            {
                                    do
                                    {

                                            fread(temp,sizeof(char),1,data);

                                            if(no==1)
                                            {
                                                    int i=0;

                                                    while(temp[0]!=' ')
                                                    {

                                                            value[index] = memory_Initialize(value[index],i,(i+1));
                                                            string_Copy(value[index],temp);

                                                            i++;

                                                            fread(temp,sizeof(char),1,data);
                                                    }

                                                    index++;

                                            }

                                    }while(temp[0]!=' ');
                                    no++;
                            }



                            fclose(data);
                            data = NULL;



                                str="";
                                str=str+value[0];
                                task->TableWidgetProcess->setItem(j,0,new QTableWidgetItem((str)));

                                str="";
                                str=str+value[1];
                                task->TableWidgetProcess->setItem(j,1,new QTableWidgetItem((str)));

                                str="";
                                str=str+value[2];
                                task->TableWidgetProcess->setItem(j,2,new QTableWidgetItem((str)));

                                str="";
                                str=str+value[3];
                                task->TableWidgetProcess->setItem(j,3,new QTableWidgetItem((str)));


                                j++;

                           // printf("%s	%s	%s	%s\n",value[0],value[1],value[2],value[3]);


                            for(index=0;index<4;index++)
                            {
                                    free(value[index]);
                                    value[index] = NULL;
                            }




                    }
            }

            for(;j<400;j++)
            {
                str="";

                task->TableWidgetProcess->setItem(j,0,new QTableWidgetItem((str)));

                task->TableWidgetProcess->setItem(j,1,new QTableWidgetItem((str)));

                task->TableWidgetProcess->setItem(j,2,new QTableWidgetItem((str)));

                task->TableWidgetProcess->setItem(j,3,new QTableWidgetItem((str)));
            }
            free(temp);

}









void TaskManager::showMemInfo()
{
            int index=0;
            char *value[5],*temp=NULL;
            QString str="";
            value[0] = NULL;
            value[1] = NULL;
            value[2] = NULL;
            value[3] = NULL;
            value[4] = NULL;


            FILE *data = fopen("/proc/meminfo","r");


            if(data==NULL)
            {
                    perror("Path not valid\n");
            }

            temp = memory_Initialize(temp,0,1);

            int check=0,i=0;

            while(index<5)
            {

                    check = 0;
                    i = 0;

                    fread(temp,sizeof(char),1,data);

                    while(temp[0]!='\n')
                    {
                            fread(temp,sizeof(char),1,data);

                            if(check==0)
                            {
                                    if(temp[0]==':')
                                    check = 1;
                            }
                            else
                            {
                                    if((check==1)&&(temp[0]!=32))
                                            check = 2;

                                    if(check==2)
                                    {
                                            value[index] = memory_Initialize(value[index],i,(i+1));
                                            string_Copy(value[index],temp);

                                            i++;
                                    }

                            }
                    }

                    index++;
            }

            str="";
            str=str+value[0];
            str=str+" kb";
            task->SysInfoTotalMemory->setText(str); //to print Total Memory
            task->sysInfoRAM->setText(str);          //to print RAM in Basic Info

            str="";
            str=str+value[1];
            str=str+" kb";
            task->SysInfoFreeMemory->setText(str); //to print Free Memory

            str="";
            str=str+value[2];
            str=str+" kb";
            task->SysInfoBuffers->setText(str);  //to print buffers

            str="";
            str=str+value[3];
            str=str+" kb";
            task->SysInfoCached->setText(str);    //to print Cache

            str="";
            str=str+value[4];
            str=str+" kb";
            task->SysInfoSwapCached->setText(str);    //to print Swap Cache

            fclose(data);
            data = NULL;

            free(temp);



        //    printf("Total Memory:\t%s\nMemory Free:\t%s\nBuffers:\t%s\nCached:\t%s\nSwaped Cache:\t%s\n",value[0],value[1],value[2],value[3],value[4]);

            for(index=0;index<5;index++)
                    free(value[index]);



}









void TaskManager::showBasicInfo()
{
    int index=0,no=0;
            char *value[3],*temp=NULL;
        QString str;
            value[0] = NULL;
            value[1] = NULL;
            value[2] = NULL;


            FILE *data = fopen("/proc/cpuinfo","r");


            if(data==NULL)
            {
                    perror("Path not valid\n");
            }

            temp = memory_Initialize(temp,0,1);

            while(no<12)
            {
                    do
                    {
                            fread(temp,sizeof(char),1,data);

                            if((no==4)||(no==7)||(no==11))
                            {
                                    int check=0,i=0;

                                    while(temp[0]!='\n')
                                    {
                                            fread(temp,sizeof(char),1,data);

                                            if(check==0)
                                            {
                                                    if(temp[0]==':')
                                                            check = 1;
                                            }
                                            else
                                            {
                                                    if((check==1)&&(temp[0]!=32))
                                                            check = 2;

                                                    if(check==2)
                                                    {
                                                            value[index] = memory_Initialize(value[index],i,(i+1));
                                                            string_Copy(value[index],temp);

                                                            i++;
                                                    }

                                            }
                                    }

                                    index++;
                            }

                    }while(temp[0]!='\n');
                    no++;
            }
            str="";
            str=str+value[0];
            task->sysInfoCPU->setText(str);     //to print cpu name


            str="";
            str=str+value[1];
            task->sysInfoCache->setText(str);     //to print chache size

            str="";
            str=str+value[2];
            task->sysInfoCores->setText(str);     //to print no of cores
            fclose(data);


            data = NULL;

            free(temp);


           // printf("CPU Name = %s\nCache Size = %s\nCores = %s\n",value[0],value[1],value[2]);

            for(index=0;index<3;index++)
                    free(value[index]);


}










void TaskManager::showBatteryInfo()
{
        int index=0,no=0;
        char *value[6],*temp=NULL;
 QString str="";
        value[0] = NULL;
        value[1] = NULL;
        value[2] = NULL;
        value[3] = NULL;
        value[4] = NULL;
        value[5] = NULL;

        FILE *data = fopen("/proc/acpi/battery/BAT0/state","r");


        if(data==NULL)
        {
                perror("Path not valid\n");
        }

        temp = memory_Initialize(temp,0,1);

        while(no<3)
        {
                do
                {
                        fread(temp,sizeof(char),1,data);

                        if((no==0)||(no==2))
                        {
                                int check=0,i=0;

                                while(temp[0]!='\n')
                                {
                                        fread(temp,sizeof(char),1,data);

                                        if(check==0)
                                        {
                                                if(temp[0]==':')
                                                        check = 1;
                                        }
                                        else
                                        {
                                                if((check==1)&&(temp[0]!=32))
                                                        check = 2;

                                                if(check==2)
                                                {
                                                        value[index] = memory_Initialize(value[index],i,(i+1));
                                                        string_Copy(value[index],temp);

                                                        i++;
                                                }

                                        }
                                }

                                index++;
                                if(index==1)
                                {
                                        check = string_Cmp(value[0],"yes");

                                        if(check=0)
                                        {
                                                no = 10;
                                        }

                                }
                        }

                }while(temp[0]!='\n');
                no++;
        }

        fclose(data);
        data = NULL;

        if(no==3)
        {
                no = 0;
                FILE *data = fopen("/proc/acpi/battery/BAT0/info","r");

                while(no<12)
                {
                        do
                        {
                                fread(temp,sizeof(char),1,data);

                                if((no==3)||(no==9)||(no==10)||(no==11))
                                {
                                        int check=0,i=0;

                                        while(temp[0]!='\n')
                                        {
                                                fread(temp,sizeof(char),1,data);

                                                if(check==0)
                                                {
                                                        if(temp[0]==':')
                                                                check = 1;
                                                }
                                                else
                                                {
                                                        if((check==1)&&(temp[0]!=32))
                                                                check = 2;

                                                        if(check==2)
                                                        {
                                                                value[index] = memory_Initialize(value[index],i,(i+1));
                                                                string_Copy(value[index],temp);

                                                                i++;
                                                        }

                                                }
                                        }

                                        index++;
                                }

                        }while(temp[0]!='\n');
                        no++;
                }

                fclose(data);
                data = NULL;
        }


        str="";
        str=str+value[0];
        task->sysInfoBatteryInfoLabelBatteryState->setText(str); //to print Battery Available or not

        str="";
        str=str+value[1];
        task->sysInfoBatteryInfoLabelAcAdapter->setText(str); //to print Ac Adapter

        str="";
        str=str+value[2];
        str=str+" kb";
        task->sysInfoBatteryInfoLabelBatteryTechnology->setText(str);  //to print Battery Technology

        str="";
        str=str+value[3];
        str=str+" kb";
        task->sysInfoBatteryInfoLabelBatteryModelNo->setText(str);    //to print Battery Model number

        str="";
        str=str+value[4];
        str=str+" kb";
        task->sysInfoBatteryInfoLabelSerialNumber->setText(str);    //to print Battery Serial number

        str="";
        str=str+value[5];
        str=str+" kb";
        task->sysInfoBatteryInfoLabelBatteryType->setText(str);    //to print Battery Type


        //        printf("Present:\t%s\nCharging State:\t%s\nTechnology:\t%s\nModel No.:\t%s\nType:\t%s",value[0],value[1],value[2],value[3],value[4]);

        free(temp);//vdjjh

        for(index=0;index<6;index++)
                free(value[index]);



}

void TaskManager::showOsVersion()
{
            int i=0;
            char *value=NULL,*temp=NULL;

            QString str="";


            temp = memory_Initialize(temp,0,1);
            value = memory_Initialize(value,0,1);

            FILE *data = fopen("/proc/version","r");


            while(fread(temp,sizeof(char),1,data))
            {
                    value = memory_Initialize(value,i,(i+1));
                    string_Copy(value,temp);

                    i++;

            }

            free(temp);

            str = str + value;

            task->sysInfoOSV->setText(str);    //to print os version
            free(value);

}



void TaskManager::showNetworkInfo()
{
    int index=0,no=0;
            char *value[4],*temp=NULL;

            QString str="",str1="",str2="",str3="";

            int i=0;
            for(i=0;i<4;i++)
                    value[i] = NULL;



            FILE *data = fopen("/proc/net/dev","r");


            if(data==NULL)
            {
                    perror("Path not valid\n");
            }

            temp = memory_Initialize(temp,0,1);

            int check1=0,count=0;



            while(!feof(data))
                    {

                                    fread(temp,sizeof(char),1,data);


                                    if((check1==0)&&(temp[0]=='e'))
                                    {
                                            check1++;

                                    }

                                    if(temp[0]=='t')
                                    {
                                            if(check1==1)
                                            {
                                                    check1++;
                                            }
                                            else
                                                    check1 = 0;
                                    }


                                    if(temp[0]=='h')
                                    {
                                            if(check1==2)
                                            {
                                                    check1++;
                                            }
                                            else
                                                    check1 = 0;
                                    }

                                    if(temp[0]=='0')
                                    {
                                            if(check1==3)
                                                    check1++;
                                            else
                                                    check1 = 0;
                                    }
                                    if(temp[0]==':')
                                    {
                                            if(check1==4)
                                                    check1++;
                                            else
                                                    check1 = 0;
                                    }




                                    if(check1>4)
                                    {
                                            int check=0,i=0;


                                            do
                                            {
                                                    fread(temp,sizeof(char),1,data);


                                                    if((check==0)&&(temp[0]>47))
                                                    {

                                                                    check = 1;
                                                    }

                                                    if((check==1)&&(temp[0]==' '))
                                                    {
                                                            check = 0;


                                                            if((no==0)||(no==1)||(no==8)||(no==9))
															{
                                                                    index++;
																	i = 0;
															}

                                                            no++;
                                                    }
                                                    else
                                                    {
                                                            if((check==1)&&((no==0)||(no==1)||(no==8)||(no==9)))
                                                            {
                                                                    value[index] = memory_Initialize(value[index],i,(i+1));
                                                                    string_Copy(value[index],temp);
                                                                    i++;
                                                            }
                                                    }
                                            }while(index<4);

                                    }




                    }

                    fclose(data);
                    data = NULL;







            FILE *abc = fopen("abc","w");
                fprintf(abc,"%s\n%s\n%s\n%s\n",value[0],value[1],value[2],value[3]);
                fclose(abc);




            i = 0;

            str="";
            str=str+value[0];
            task->bytesReceived->setText(str);    //to print Battery Type

            str1="";
            str1=value[1];
            task->packetsReceived->setText(str1);    //to print Battery Type

            str2="";
            str2=str2+value[2];
            task->bytesSent->setText(str2);    //to print Battery Type

            str3="";
            str3=str3+value[3];
            task->packetsSent->setText(str3);    //to print Battery Type








}










safe_Remove::safe_Remove(QWidget *parent) :
    QMainWindow(parent),
    safeRemove(new Ui::safe_Remove)
{
    safeRemove->setupUi(this);
}

safe_Remove::~safe_Remove()
{
    delete safeRemove;
}

void safe_Remove::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        safeRemove->retranslateUi(this);
        break;
    default:
        break;
    }
}




void UtilityManager::on_checkSafeRemove_clicked()
{
    int i=-1,ans=-1;

    for(i=0;i<totalDisk;i++)
    {
        if(radioButton[i]->isChecked())
        {

            ans  = i;
        }
    }


    if(ans>=0)
    {
        int index=0;
        char *value=NULL,*temp=NULL;



        FILE *data = fopen("/proc/mounts","r");


        if(data==NULL)
        {
                perror("Path not valid\n");
        }

        temp = memory_Initialize(temp,0,1);

        int check1=0,count=0;

        while(!feof(data))
        {

                count = 0;

                do
                {
                        count++;
                        fread(temp,sizeof(char),1,data);

                        if((count==1)&&(temp[0]=='g'))
                                check1++;


                        if((count==2)&&(temp[0]=='v'))
                                check1++;


                        if((count==3)&&(temp[0]=='f'))
                                check1++;


                        if((count==4)&&(temp[0]=='s'))
                                check1++;




                        if(check1>4)
                        {
                                int check=0,i=0;





                                while(temp[0]!='\n')
                                {
                                        fread(temp,sizeof(char),1,data);

                                        if(index==ans)
                                        {
                                                if((check==0)&&(temp[0]==' '))
                                                {

                                                                check = 1;
                                                }
                                                else
                                                {

                                                        if((check==1)&&(temp[0]==' '))
                                                                check = 2;
                                                        else
                                                        {
                                                                if(check==1)
                                                                {
                                                                        value = memory_Initialize(value,i,(i+1));
                                                                        string_Copy(value,temp);

                                                                        i++;

                                                                }
                                                        }
                                                }
                                        }
                                }

                                index++;
                        }

                }while(temp[0]!='\n');

                if(check1==4)
                        check1++;

        }



        fclose(data);
        data = NULL;

        free(temp);
        temp = NULL;


        QString mountPoint="";

        mountPoint = mountPoint + value;

        if(value!=NULL)
        {
            int index=0,i=0;
            char *path=NULL,*temp=NULL;
            DIR *proc_Dir=NULL;
            struct dirent *pid=NULL;


            temp = NULL;

            proc_Dir = opendir("/proc/");

            while((pid=readdir(proc_Dir))!=NULL)
            {
                    if((pid->d_name[0]>47)&&(pid->d_name[0]<58))
                    {
                            int length=0,check=0;
                            char *linked_File=NULL;

                            path = memory_Initialize(path,0,10+strlen(pid->d_name));

                            string_Copy(path,"/proc/");
                            string_Copy(path,pid->d_name);
                            string_Copy(path,"/exe");

                            linked_File = memory_Initialize(linked_File,0,256);

                            length = readlink(path,linked_File,256);

                            free(path);
                            path = NULL;

                            check = string_Part_Cmp(linked_File,value);

                            if(check==1)
                            {
                                    foundPid = (char **)realloc(foundPid,(index+1)*sizeof(char *));

                                    foundPid[index] = NULL;

                                    foundPid[index] = memory_Initialize(foundPid[index],0,strlen(pid->d_name));
                                    string_Copy(foundPid[index],pid->d_name);
                                    index++;

                            }

                            memory_Int(linked_File,length);

                            if(check!=1)
                            {
                                    path = memory_Initialize(path,0,10+strlen(pid->d_name));

                                    string_Copy(path,"/proc/");
                                    string_Copy(path,pid->d_name);
                                    string_Copy(path,"/cwd");

                                    length = readlink(path,linked_File,256);

                                    free(path);
                                    path = NULL;

                                    check = string_Part_Cmp(linked_File,value);



                                    if(check==1)
                                    {
                                            foundPid = (char **)realloc(foundPid,(index+1)*sizeof(char *));

                                            foundPid[index] = NULL;

                                            foundPid[index] = memory_Initialize(foundPid[index],0,strlen(pid->d_name));
                                            string_Copy(foundPid[index],pid->d_name);
                                            index++;


                                    }

                                    memory_Int(linked_File,length);
                            }

                            DIR *fd_Dir=NULL;
                            struct dirent *fd=NULL;

                            path = memory_Initialize(path,0,10+strlen(pid->d_name));
                            string_Copy(path,"/proc/");
                            string_Copy(path,pid->d_name);
                            string_Copy(path,"/fd/");

                            fd_Dir = opendir(path);

                            free(path);
                            path = NULL;

                            while((check!=1)&&((fd=readdir(fd_Dir))!=NULL))
                            {
                                    if((fd->d_type)==DT_LNK)
                                    {
                                            path = memory_Initialize(path,0,10+strlen(pid->d_name)+strlen(fd->d_name));
                                            string_Copy(path,"/proc/");
                                            string_Copy(path,pid->d_name);
                                            string_Copy(path,"/fd/");
                                            string_Copy(path,fd->d_name);

                                            length = readlink(path,linked_File,256);

                                            free(path);
                                            path = NULL;

                                            check = string_Part_Cmp(linked_File,value);


                                            if(check==1)
                                            {
                                                    foundPid = (char **)realloc(foundPid,(index+1)*sizeof(char *));

                                                    foundPid[index] = NULL;

                                                    foundPid[index] = memory_Initialize(foundPid[index],0,strlen(pid->d_name));
                                                    string_Copy(foundPid[index],pid->d_name);
                                                    index++;
                                            }

                                            memory_Int(linked_File,length);



                                    }
                            }

                    }
            }

            selectedMountPoint = (char *)malloc((strlen(value)+1)*sizeof(char));
            memory_Int(selectedMountPoint,(strlen(value)+1));
            string_Copy(selectedMountPoint,value);


            if(index>0)
            {
                int j=0;
                QLabel *text;
                totalPid = index;



                QString str="";

                UnmountDisk *setPid = new UnmountDisk();


                QGridLayout* grid = new QGridLayout(setPid->centralWidget());


                if((index%2)==0)
                {
                    j = (index/2)-1;
                }
                else
                {
                    j = (index-1)/2;
                }

                for(i=0;i<index;i++)
                {
                    str = "";
                    str = str + foundPid[i];

                    text = new QLabel(str,(setPid->centralWidget()));
                    grid->addWidget(text,i,1);
                    
                    if(i==j)
                    {
                        QPushButton *button = new QPushButton("Unmount",setPid->centralWidget());
                        grid->addWidget(button,i,2);
                        connect(button, SIGNAL(clicked()), SLOT(on_unmount_clicked()));
                    }

                }

                setPid->show();

            }
            else
            {
                QLabel *text;
                totalPid = 0;
                QString str="";


                UnmountDisk *setPid = new UnmountDisk();

                QGridLayout* grid = new QGridLayout(setPid->centralWidget());
                text = new QLabel("No Process Is Running \n In This Device Press Unmount \nTo Unmount This Device",(setPid->centralWidget()));
                grid->addWidget(text,1,1);

                QPushButton *button = new QPushButton("Unmount",setPid->centralWidget());
                grid->addWidget(button,1,2);
                connect(button, SIGNAL(clicked()), SLOT(on_unmount_clicked()));

                setPid->show();

            }



        }
        else
        {
            QMessageBox msgBox;
            msgBox.setText("Drive Has Already Been Unmounted Please Close and Start Again");
            msgBox.exec();
        }

        free(value);


    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("No Disk Mounted");
        msgBox.exec();
    }


}




























UnmountDisk::UnmountDisk(QWidget *parent) :
    QMainWindow(parent),
    unmount(new Ui::UnmountDisk)
{
    unmount->setupUi(this);
}

UnmountDisk::~UnmountDisk()
{
    delete unmount;
}

void UnmountDisk::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        unmount->retranslateUi(this);
        break;
    default:
        break;
    }
}







void UtilityManager::on_unmount_clicked()
{
    int index=0;
    index = totalPid;
    pid_t pid=0;

    if(index>0)
    {
        for(int i=0;i<index;i++)
        {
            pid = atoi(foundPid[i]);
            kill(pid,9);
        }
    }


    pid = fork();

    if(pid==0)
    {
        char *command=NULL;

        command = memory_Initialize(command,0,6);
        string_Copy(command,"umount");

        execl("/bin/umount",command,selectedMountPoint,(char *)0);
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Your Drive Has Been Successfully Unmounted");
        msgBox.exec();
    }
    //umount(selectedMountPoint);



}
