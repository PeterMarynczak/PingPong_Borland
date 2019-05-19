//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TImage *p1;
        TShape *tlo;
        TImage *p2;
        TTimer *goraL;
        TTimer *dolL;
        TTimer *goraP;
        TTimer *dolP;
        TImage *ball;
        TTimer *Timer_pilka;
        void __fastcall goraLTimer(TObject *Sender);
        void __fastcall dolLTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall goraPTimer(TObject *Sender);
        void __fastcall dolPTimer(TObject *Sender);
        void __fastcall Timer_pilkaTimer(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
