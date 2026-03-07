#include<windows.h>

void AutoHideTaskBar(BOOL bHide)
{

    LPARAM lParam;
    if (bHide == TRUE)
    {
        lParam = ABS_ALWAYSONTOP;
    }
    else
    {
        lParam = ABS_AUTOHIDE;
    }

    APPBARDATA apBar;
    memset(&apBar, 0, sizeof(apBar));
    apBar.cbSize = sizeof(apBar);
    apBar.hWnd = FindWindowA(NULL, NULL);
    if (apBar.hWnd != NULL)
    {
        apBar.lParam = lParam;
        SHAppBarMessage(ABM_SETSTATE, &apBar);
    }
}
int main()
{
    AutoHideTaskBar(FALSE);  //TRUE=The taskbar is in the always-on-top state.
    //FALSE=AUTHIDE

}