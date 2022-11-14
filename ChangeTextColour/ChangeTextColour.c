#include <stdio.h>
#include <windows.h>

int main()
{
    /**
     * HANDLE is a Windows API datatype
     * It's a pointer to a "handle".
     * Handles, and the many other similar types in Windows, are generally pointers to
     * files and the like.
     * In this case, when you write a C program, you have 3 "files" already opened for you:
     *
     * stdout
     * stdin
     * stderr
     *
     * You may not realize you're using them. When you use printf(), you're writing to stdout.
     * When you use scanf(), you're reading from stdin.
     * The code gets the HANDLE associated with stdout. * .
     */
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    /**
     * This is a WORD datatype variable that is going to be used to store the old data color info.
     * If you change the color of the console text in your application,
     * when your program is terminated, the color will not revert back to what it was before.
     * That is your job to set it back to normal..
     */
    WORD wOldColorAttrs;

    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;

    /**
     * First save the current color information.
     */
    GetConsoleScreenBufferInfo(h, &csbiInfo);
    wOldColorAttrs = csbiInfo.wAttributes;

    /**
     * Set the new color information
     */
    SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);

    printf("This is a test\n");

    SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);

    printf("This is a test\n");

    SetConsoleTextAttribute(h, BACKGROUND_BLUE | FOREGROUND_INTENSITY);

    printf("This is a test\n");

    /**
     * Restore the original colors.
     */
    SetConsoleTextAttribute(h, wOldColorAttrs);

    printf("This is a test\n");

    return 0;
}
