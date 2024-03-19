#include <iostream>
#include <graphics.h>

using namespace std;

const int INSIDE = 0; // Bit code for the inside region of the clip window
const int LEFT = 1;   // Bit code for the left region of the clip window
const int RIGHT = 2;  // Bit code for the right region of the clip window
const int BOTTOM = 4; // Bit code for the bottom region of the clip window
const int TOP = 8;    // Bit code for the top region of the clip window

int computeOutCode(int x, int y, int xmin, int ymin, int xmax, int ymax)
{
    int code = INSIDE;

    if (x < xmin)
    {
        code |= LEFT;
    }
    else if (x > xmax)
    {
        code |= RIGHT;
    }

    if (y < ymin)
    {
        code |= BOTTOM;
    }
    else if (y > ymax)
    {
        code |= TOP;
    }

    return code;
}

void cohenSutherland(int x1, int y1, int x2, int y2, int xmin, int ymin, int xmax, int ymax)
{
    int outcode1 = computeOutCode(x1, y1, xmin, ymin, xmax, ymax);
    int outcode2 = computeOutCode(x2, y2, xmin, ymin, xmax, ymax);
    bool accept = false;

    while (true)
    {
        if ((outcode1 == 0) && (outcode2 == 0))
        {
            // Both endpoints are inside the clip window
            accept = true;
            break;
        }
        else if (outcode1 & outcode2)
        {
            // Both endpoints are outside the same region, so the line is completely outside
            break;
        }
        else
        {
            // Line is partially inside. Compute intersection points and clip the line
            int x, y;

            int outcodeOut = outcode1 ? outcode1 : outcode2;

            if (outcodeOut & TOP)
            {
                x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
                y = ymax;
            }
            else if (outcodeOut & BOTTOM)
            {
                x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
                y = ymin;
            }
            else if (outcodeOut & RIGHT)
            {
                y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
                x = xmax;
            }
            else if (outcodeOut & LEFT)
            {
                y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
                x = xmin;
            }

            if (outcodeOut == outcode1)
            {
                x1 = x;
                y1 = y;
                outcode1 = computeOutCode(x1, y1, xmin, ymin, xmax, ymax);
            }
            else
            {
                x2 = x;
                y2 = y;
                outcode2 = computeOutCode(x2, y2, xmin, ymin, xmax, ymax);
            }
        }
    }

    if (accept)
    {
        setcolor(LIGHTGREEN);
        line(x1, y1, x2, y2);
    }
}

void adjust(int &x, int &y, int center_x, int center_y)
{
    x -= center_x;
    y = center_y - y; // Invert y-coordinate
}

int main()
{
    int screenWidth = 800;
    int screenHeight = 600;
    int centerX = screenWidth / 2;
    int centerY = screenHeight / 2;

    initwindow(screenWidth, screenHeight, "Clipping");

    line(0, centerY, screenWidth, centerY);
    line(centerX, 0, centerX, screenHeight);

    int xmin, ymin , xmax , ymax ;
     cout << "Enter coordinates of the clipping window (xmin ymin xmax ymax): ";
     cin >> xmin >> ymin >> xmax >> ymax;

    rectangle(xmin + centerX, centerY - ymax, xmax + centerX, centerY - ymin);

    int numLines;
    cout << "Enter the number of sides of polygon: ";
    cin >> numLines;
    
    int x1[numLines], y1[numLines], x2[numLines], y2[numLines];
    for (int i = 0; i < numLines; ++i)
    {
        cout << "Enter coordinates of sides of polygon " << (i + 1) << " (x1 y1 x2 y2): ";
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
        setcolor(WHITE);
        line(x1[i] + centerX, centerY - y1[i], x2[i] + centerX, centerY - y2[i]);
    }
    delay(2000);
    for (int i = 0; i < numLines; ++i)
    {
        setcolor(WHITE);
        line(x1[i] + centerX, centerY - y1[i], x2[i] + centerX, centerY - y2[i]);
        // delay(3000);
        setcolor(BLACK);
        line(x1[i] + centerX, centerY - y1[i], x2[i] + centerX, centerY - y2[i]);
        cohenSutherland(x1[i] + centerX, centerY - y1[i], x2[i] + centerX, centerY - y2[i], xmin + centerX, centerY - ymax, xmax + centerX, centerY - ymin);
    }

    delay(5000); // Wait for 5 seconds before closing the window
    closegraph();
    return 0;
}
