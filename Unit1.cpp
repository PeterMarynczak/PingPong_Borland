//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

double x = -6;
double y = -6;
int iloscOdbic = 0;
char kto;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm1::goraLTimer(TObject *Sender)
{
   if(p1->Top > 10) p1->Top -= 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::dolLTimer(TObject *Sender)
{
   if(p1->Top+p1->Height < tlo->Height - 10) p1->Top += 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
   if (Key == 0x41) goraL->Enabled = true;
   if (Key == 0x5A) dolL->Enabled = true;
   if (Key == VK_UP) goraP->Enabled = true;
   if (Key == VK_DOWN) dolP->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
   if (Key == 0x41) goraL->Enabled = false;
   if (Key == 0x5A) dolL->Enabled = false;
   if (Key == VK_UP) goraP->Enabled = false;
   if (Key == VK_DOWN) dolP->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::goraPTimer(TObject *Sender)
{
   if(p2->Top > 10) p2->Top -= 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::dolPTimer(TObject *Sender)
{
   if(p2->Top + p2->Height < tlo->Height - 10) p2->Top += 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer_pilkaTimer(TObject *Sender)
{
   ball->Left += x;
   ball->Top += y;

   //odbij od gornej sciany
   if(ball->Top-5 <= tlo->Top)  y = -y;

   //odbij od dolnej sciany
   if(ball->Top + ball->Height >= tlo->Height)  y = -y;

   //odbicie od lewej paletki
   if (ball->Left <= p1->Left+p1->Width && ball->Top >= p1->Top-20 &&
       ball->Top+ball->Height <= p1->Top+p1->Height+20 )
        {
            x *= -1;
            x*= 1.1;
            iloscOdbic++;
            kto = 'l';
        }

   //odbicie od prawej paletki
   if (ball->Left + ball->Width >= p2->Left && ball->Top >= p2->Top-15
            && ball->Top + ball->Height <= p2->Top + p2->Height+15 )
        {
            x *= -1;
            x*= 1.1;
            iloscOdbic++;
            kto = 'p';
        }

   // przegrana
   if( (ball->Left < p1->Left) || (ball->Left > p2->Left) )
     {
       Timer_pilka->Enabled = false;
       ball->Visible = false;
       Button1->Visible = true;
       Label1->Visible = true;
       Label1->Caption = "Iloœæ odbiæ: " + IntToStr(iloscOdbic);
       Label2->Visible = true;
       }
       if (kto == 'l')
         Label2->Caption = "< Punkt dla gracza lewego";
       else if (kto == 'p')
         Label2->Caption = " Punkt dla gracza prawego >";
   }
//---------------------------------------------------------------------------


void __fastcall TForm1::Button1Click(TObject *Sender)
{
     ball->Left = 700;
     ball->Top =  250;
     iloscOdbic = 0;
     kto = NULL;

     ball->Visible = true;
     x = -6;
     y = -6;
     Timer_pilka->Enabled = true;

     Button1->Visible = false;
     Label1->Visible = false;
     Label2->Visible = false;
}
//---------------------------------------------------------------------------


