#include <graphics.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <algorithm>
#include <conio.h>

using namespace std;

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    setbkcolor(LIGHTGRAY);

    int barWidth = 20;
    int barHeight = 100;
    int spaceBetweenBars = 50;
    int minY = 50;
    int maxY = getmaxy();
    int barX = getmaxx() - barWidth;

    int redBarY = minY;
    int greenBarY = minY + spaceBetweenBars;
    int blueBarY = minY + 2 * spaceBetweenBars;

    int redBarVelocity = 5;
    int greenBarVelocity = 7;
    int blueBarVelocity = 9;

    int redColor = RED;
    int greenColor = GREEN;
    int blueColor = BLUE;

    int scoreRed = 0;
    int scoreGreen = 0;
    int scoreBlue = 0;

    int ballRadius = 20;

    srand(time(NULL));

    int yellowColor = YELLOW;
    int cyanColor = CYAN;
    int magentaColor = MAGENTA;
    int otherColor = LIGHTGRAY;

    vector<int> colors;
    for (int i = 0; i < 9; ++i)
    {
        if (i < 2)
            colors.push_back(redColor);
        else if (i < 4)
            colors.push_back(greenColor);
        else if (i < 6)
            colors.push_back(blueColor);
        else if (i == 6)
            colors.push_back(yellowColor);
        else if (i == 7)
            colors.push_back(cyanColor);
        else if (i == 8)
            colors.push_back(magentaColor);
        else
            colors.push_back(otherColor);
    }

    vector<int> ballX;
    for (int i = 0; i < colors.size(); ++i)
    {
        ballX.push_back(rand() % (getmaxx() + ballRadius) / 2);
    }
    vector<int> ballY;
    for (int i = 0; i < colors.size(); ++i)
    {
        ballY.push_back(rand() % (getmaxy() - ballRadius * 2) + ballRadius);
    }
    vector<int> ballVelocitiesX(colors.size(), rand() % 5 + 5);
    vector<int> ballVelocitiesY(colors.size(), rand() % 5 + 5);
    vector<int> ballDirectionsX(colors.size(), 1);
    vector<int> ballDirectionsY(colors.size(), 1);

    while (!kbhit())
    {
        clearviewport();

        redBarY += redBarVelocity;
        greenBarY += greenBarVelocity;
        blueBarY += blueBarVelocity;

        if (redBarY <= minY || redBarY + barHeight >= maxY)
        {
            redBarVelocity *= -1;
        }

        if (greenBarY <= minY || greenBarY + barHeight >= maxY)
        {
            greenBarVelocity *= -1;
        }

        if (blueBarY <= minY || blueBarY + barHeight >= maxY)
        {
            blueBarVelocity *= -1;
        }

        setcolor(redColor);
        setfillstyle(SOLID_FILL, redColor);
        bar(barX, redBarY, barX + barWidth, redBarY + barHeight);

        setcolor(greenColor);
        setfillstyle(SOLID_FILL, greenColor);
        bar(barX, greenBarY, barX + barWidth, greenBarY + barHeight);

        setcolor(blueColor);
        setfillstyle(SOLID_FILL, blueColor);
        bar(barX, blueBarY, barX + barWidth, blueBarY + barHeight);

        for (int i = 0; i < colors.size(); ++i)
        {
            ballX[i] += ballVelocitiesX[i] * ballDirectionsX[i];
            if (ballX[i] >= barX - barWidth || ballX[i] - ballRadius <= 0)
            {
                ballDirectionsX[i] *= -1;

                if (ballX[i] - ballRadius > 0)
                {
                    setcolor(YELLOW);
                    circle(barX, ballY[i], 10);
                    int hitBarColor = getpixel(barX + 10, ballY[i]);
                    if (hitBarColor == colors[i] && colors[i] == RED)
                    {
                        scoreRed += 4;
                    }
                    else if (hitBarColor == colors[i] && colors[i] == GREEN)
                    {
                        scoreGreen += 4;
                    }
                    else if (hitBarColor == colors[i] && colors[i] == BLUE)
                    {
                        scoreBlue += 4;
                    }
                    else if (hitBarColor && colors[i] && colors[i] != GREEN && colors[i] != RED && colors[i] != BLUE && hitBarColor == RED)
                    {
                        scoreRed--;
                    }
                    else if (hitBarColor && colors[i] && colors[i] != GREEN && colors[i] != RED && colors[i] != BLUE && hitBarColor == GREEN)
                    {
                        scoreGreen--;
                    }
                    else if (hitBarColor && colors[i] && colors[i] != GREEN && colors[i] != RED && colors[i] != BLUE && hitBarColor == BLUE)
                    {
                        scoreBlue--;
                    }
                }
            }

            ballY[i] += ballVelocitiesY[i] * ballDirectionsY[i];
            if (ballY[i] > getmaxy() - ballRadius - 5 || ballY[i] <= ballRadius)
            {
                ballDirectionsY[i] *= -1;
            }

            setcolor(colors[i]);
            setfillstyle(SOLID_FILL, colors[i]);
            fillellipse(ballX[i], ballY[i], ballRadius, ballRadius);
        }

        setcolor(BLACK);
        const char *scoreText = "Score: ";
        outtextxy(20, 20, const_cast<char *>(scoreText));

        char redScoreText[10], greenScoreText[10], blueScoreText[10];
        sprintf(redScoreText, "Red: %d", scoreRed);
        sprintf(greenScoreText, "Green: %d", scoreGreen);
        sprintf(blueScoreText, "Blue: %d", scoreBlue);

        outtextxy(20, 40, redScoreText);
        outtextxy(20, 60, greenScoreText);
        outtextxy(20, 80, blueScoreText);

        if (scoreRed >= 10 || scoreGreen >= 10 || scoreBlue >= 10)
        {
            clearviewport();
            setcolor(BLACK);
            settextstyle(4, 0, 6);
            const char *winners = "WINNER(S):";
            outtextxy(100, getmaxy() / 2 - 50, const_cast<char *>(winners));
            delay(500);
            if (scoreRed >= 10)
            {
                const char *red_w = "RED";
                outtextxy(100, getmaxy() / 2 + 50, const_cast<char *>(red_w));
            }
            if (scoreGreen >= 10)
            {
                const char *green_w = "GREEN";
                outtextxy(100, getmaxy() / 2 + 50, const_cast<char *>(green_w));
            }
            if (scoreBlue >= 10)
            {
                const char *blue_w = "BLUE";
                outtextxy(100, getmaxy() / 2 + 50, const_cast<char *>(blue_w));
            }
            const char *out = "Press any key to exit...";
            outtextxy(100, getmaxy() / 2 + 100, const_cast<char *>(out));
            break;
        }

        delay(50);
    }

    while (!kbhit())
    {
        delay(100);
    }

    closegraph();
    return 0;
}
