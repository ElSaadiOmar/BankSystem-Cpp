#include "C:\Users\elssa\Desktop\Problem\BankFile\Screens\Useres\clsLoginScreen.h"
int main()
{

  clsUser User = clsUser::Find("User1","1234");
  // clsMainScreen::ShowMainMenu();
  while (true)
  {
    if (!clsLoginScreen::ShowLoginScreen())
      break;
  }
}