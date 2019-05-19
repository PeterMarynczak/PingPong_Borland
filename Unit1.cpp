//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
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
