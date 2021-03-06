//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "mmsystem.h"

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TPingPong *PingPong;

double x = 0;
double y = 0;
int iloscOdbic = 0;
char kto;
int wynik_lewy = 0;
int wynik_prawy = 0;
int czynowagra = true;


//---------------------------------------------------------------------------
__fastcall TPingPong::TPingPong(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TPingPong::goraLTimer(TObject *Sender)
{
   if(p1->Top > 10) p1->Top -= 10;
}
//---------------------------------------------------------------------------

void __fastcall TPingPong::dolLTimer(TObject *Sender)
{
   if(p1->Top+p1->Height < tlo->Height - 10) p1->Top += 10;
}
//---------------------------------------------------------------------------

void __fastcall TPingPong::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
   if (Key == 0x41) goraL->Enabled = true;
   if (Key == 0x5A) dolL->Enabled = true;
   if (Key == VK_UP) goraP->Enabled = true;
   if (Key == VK_DOWN) dolP->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TPingPong::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
   if (Key == 0x41) goraL->Enabled = false;
   if (Key == 0x5A) dolL->Enabled = false;
   if (Key == VK_UP) goraP->Enabled = false;
   if (Key == VK_DOWN) dolP->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TPingPong::goraPTimer(TObject *Sender)
{
   if(p2->Top > 10) p2->Top -= 10;
}
//---------------------------------------------------------------------------
void __fastcall TPingPong::dolPTimer(TObject *Sender)
{
   if(p2->Top + p2->Height < tlo->Height - 10) p2->Top += 10;
}
//---------------------------------------------------------------------------
void __fastcall TPingPong::Timer_pilkaTimer(TObject *Sender)
{
   ball->Left += x;
   ball->Top += y;

   //odbij od gornej sciany
   if(ball->Top-5 <= tlo->Top)
   {
    sndPlaySound("snd/wall.wav",SND_ASYNC);
    y = -y;
   }

   //odbij od dolnej sciany
   if(ball->Top + ball->Height >= tlo->Height)
   {
     sndPlaySound("snd/wall.wav",SND_ASYNC);
     y = -y;
   }

   //odbicie od lewej paletki
   if (ball->Left <= p1->Left+p1->Width && ball->Top >= p1->Top-20 &&
       ball->Top+ball->Height <= p1->Top+p1->Height+20 )
        {

        if(ball->Top > p1->Top-70 && ball->Top < p1->Top+120)
              {
                sndPlaySound("snd/ball.wav",SND_ASYNC);
                x*= 1.2;
                x *= -1;
                iloscOdbic++;
                kto = 'l';
              }
        else
             {
               sndPlaySound("snd/ball.wav",SND_ASYNC);
               x *= -1;
               x*= 1.05;
               iloscOdbic++;
               kto = 'l';
             }
        }

   //odbicie od prawej paletki
   if (ball->Left + ball->Width >= p2->Left && ball->Top >= p2->Top-15
            && ball->Top + ball->Height <= p2->Top + p2->Height+15 )
        if(ball->Top > p1->Top-70 && ball->Top < p1->Top+120)
              {
               sndPlaySound("snd/ball.wav",SND_ASYNC);
                x*= 1.2;
                x *= -1;
                iloscOdbic++;
                kto = 'p';
              }
        else
            {
                sndPlaySound("snd/ball.wav",SND_ASYNC);
                x *= -1;
                x*= 1.05;
                iloscOdbic++;
                kto = 'p';
            }

   // przegrana
   if( (ball->Left < p1->Left) || (ball->Left > p2->Left) )
     {

       if (kto == 'l')
       {
         sndPlaySound("snd/fanfar.wav",SND_ASYNC);
         Label2->Caption = "< Punkt dla gracza lewego";
         winL->Visible = true;
         wynik_lewy++;
       }
       else if (kto == 'p')
       {
         sndPlaySound("snd/fanfar.wav",SND_ASYNC);
         Label2->Caption = " Punkt dla gracza prawego >";
         winP->Visible = true;
         wynik_prawy++;
       }
       Timer_pilka->Enabled = false;
       ball->Visible = false;
       Button1->Visible = true;
       Button2->Visible = true;
       Label1->Visible = true;
       Label1->Caption = "Ilo�� odbi�: " + IntToStr(iloscOdbic);
       Label2->Visible = true;
       wynik->Caption = IntToStr(wynik_lewy) + ":" + IntToStr(wynik_prawy);
       wynik->Visible = true;
       }
   }
//---------------------------------------------------------------------------


void __fastcall TPingPong::FormCreate(TObject *Sender)
{
     Label2->Visible = true;
     Label2->Caption = "Zagrajmy w PingPonga!";
     winL->Visible = false;
     winP->Visible = false;
     Button2->Visible = true;
     Timer_pilka->Enabled = false;
     ball->Left = 700;
     ball->Top =  250;
     iloscOdbic = 0;
     kto = NULL;

     ball->Visible = true;
     Button1->Visible = false;
     Label1->Visible = false;
     wynik->Visible = false;
}
//---------------------------------------------------------------------------




void __fastcall TPingPong::Button2Click(TObject *Sender)
{
   sndPlaySound("snd/click1.wav",SND_ASYNC);
   if (czynowagra == true)
    {
     ball->Left = 700;
     ball->Top =  250;
     iloscOdbic = 0;
     kto = NULL;
     wynik_lewy = 0;
     wynik_prawy = 0;
     winL->Visible = false;
     winP->Visible = false;
     ball->Visible = true;
     x = -6;
     y = -6;
     Timer_pilka->Enabled = true;

     Button1->Visible = false;
     Button2->Visible = false;
     Label1->Visible = false;
     Label2->Visible = false;
     wynik->Visible = false;
     czynowagra = false;
    }
    else if( Application->MessageBox(
     "Czy na pewno zacz�� od nowa?","Potwierd�",
     MB_YESNO | MB_ICONQUESTION) == IDYES )
     {
     ball->Left = 700;
     ball->Top =  250;
     iloscOdbic = 0;
     kto = NULL;
     wynik_lewy = 0;
     wynik_prawy = 0;

     ball->Visible = true;
     x = -6;
     y = -6;
     Timer_pilka->Enabled = true;
     winL->Visible = false;
     winP->Visible = false;
     Button1->Visible = false;
     Button2->Visible = false;
     Label1->Visible = false;
     Label2->Visible = false;
     wynik->Visible = false;
     czynowagra = false;
    }
}
//---------------------------------------------------------------------------


void __fastcall TPingPong::Button1Click(TObject *Sender)
{
     sndPlaySound("snd/click1.wav",SND_ASYNC);

     ball->Left = 700;
     ball->Top =  250;
     iloscOdbic = 0;
     kto = NULL;

     ball->Visible = true;
     x = -6;
     y = -6;
     Timer_pilka->Enabled = true;
     winL->Visible = false;
     winP->Visible = false;
     Button1->Visible = false;
     Button2->Visible = false;
     Label1->Visible = false;
     Label2->Visible = false;
     wynik->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TPingPong::btnShowMsgClick(TObject *Sender)
 {
     ShowMessage("Witaj w grze PingPong.\n\n"
"Lewy gracz steruje wciskaj�c klawisze A do Z.\n"
"Prawy gracz steruje wciskaj�c strza�ki do g�ry i w d�.\n\n"

"Dla urozmaicenia zabawy:"
"Kiedy odbijesz pi�k� na �rodku paletki, w�wczas pi�ka przyspieszy.\n"
"Im d�u�ej odbijasz, tym pi�ka szybciej przemieszcza si�.\n"
"Mo�esz dowolnie zmienia� pole gry.\n\n"

"Mi�ej zabawy!\n");
}
//---------------------------------------------------------------------------

