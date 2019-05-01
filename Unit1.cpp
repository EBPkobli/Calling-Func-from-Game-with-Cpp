//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#include <Unit2.h>
#pragma hdrstop

#pragma argsused

DWORD WINAPI Fonksiyon1( LPVOID lpParam )
{
        Application->Initialize();
        Application->CreateForm(__classid(TForm2), &Form2);
        Application->Run();
        return 0;
}
DWORD WINAPI Fonksiyon2( LPVOID lpParam )
{
        while(true)
        {
          if(Form2!=NULL)
          {
             if(Form2->MesajVar)
             {
                ((void(__cdecl*)(const char* string))0x46b060)("Furkan Kubilay");
                Form2->MesajVar=false;
             }
          }
        }
}

int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void* lpReserved)
{
        switch(reason)
        {

               case 0x0:
               break;
               case 0x1:  //Giri� 0x0 ��k��
                CreateThread(NULL,0,Fonksiyon1,NULL,0,0);
                CreateThread(NULL,0,Fonksiyon2,NULL,0,0);
               break;

        }
        return 1;
}
//---------------------------------------------------------------------------
 