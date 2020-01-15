#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float red = image[i][j].rgbtRed;
            float green = image[i][j].rgbtGreen;
            float blue = image[i][j].rgbtBlue;
            int grey = round((red + green + blue) / 3);
            image[i][j].rgbtRed = grey;
            image[i][j].rgbtGreen = grey;
            image[i][j].rgbtBlue = grey;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;
            int end = width - j - 1;

            image[i][j].rgbtRed = image[i][end].rgbtRed;
            image[i][j].rgbtGreen = image[i][end].rgbtGreen;
            image[i][j].rgbtBlue = image[i][end].rgbtBlue;

            image[i][end].rgbtRed = red;
            image[i][end].rgbtGreen = green;
            image[i][end].rgbtBlue = blue;

        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE image2[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float red = 0;
            float green = 0;
            float blue = 0;
            int n = 0;

            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    if (((i + k) >= 0) && ((i + k) < height) && ((j + l) >= 0 && ((j + l) < width)))
                    {
                        red += image[i + k][j + l].rgbtRed;
                        green += image[i + k][j + l].rgbtGreen;
                        blue += image[i + k][j + l].rgbtBlue;
                        n++;
                    }
                }
            }
            image2[i][j].rgbtRed = round(red / n);
            image2[i][j].rgbtGreen = round(green / n);
            image2[i][j].rgbtBlue = round(blue / n);
            printf("%d %d %d\n", image2[i][j].rgbtRed, image2[i][j].rgbtGreen, image2[i][j].rgbtBlue);
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = image2[i][j].rgbtRed;
            image[i][j].rgbtGreen = image2[i][j].rgbtGreen;
            image[i][j].rgbtBlue = image2[i][j].rgbtBlue;
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE g[height][width];
    int gxMatrix[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int gyMatrix[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            double gxRed = 0;
            double gxGreen = 0;
            double gxBlue = 0;
            double gyRed = 0;
            double gyGreen = 0;
            double gyBlue = 0;

            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    if (((i + k) >= 0) && ((i + k) < height) && ((j + l) >= 0 && ((j + l) < width)))
                    {
                        gxRed += image[i + k][j + l].rgbtRed * gxMatrix[k + 1][l + 1];
                        gxGreen += image[i + k][j + l].rgbtGreen * gxMatrix[k + 1][l + 1];
                        gxBlue += image[i + k][j + l].rgbtBlue * gxMatrix[k + 1][l + 1];
                        gyRed += image[i + k][j + l].rgbtRed * gyMatrix[k + 1][l + 1];
                        gyGreen += image[i + k][j + l].rgbtGreen * gyMatrix[k + 1][l + 1];
                        gyBlue += image[i + k][j + l].rgbtBlue * gyMatrix[k + 1][l + 1];
                    }
                }
            }

            if (round(sqrt(gxRed * gxRed + gyRed * gyRed)) > 255)
            {
                g[i][j].rgbtRed = 255;
            }
            else
            {
                g[i][j].rgbtRed = round(sqrt(gxRed * gxRed + gyRed * gyRed));
            }
            if (round(sqrt(gxGreen * gxGreen + gyGreen * gyGreen)) > 255)
            {
                g[i][j].rgbtGreen = 255;
            }
            else
            {
                g[i][j].rgbtGreen = round(sqrt(gxGreen * gxGreen + gyGreen * gyGreen));
            }
            if (round(sqrt(gxBlue * gxBlue + gyBlue * gyBlue)) > 255)
            {
                g[i][j].rgbtBlue = 255;
            }
            else
            {
                g[i][j].rgbtBlue = round(sqrt(gxBlue * gxBlue + gyBlue * gyBlue));
            }
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = g[i][j].rgbtRed;
            image[i][j].rgbtGreen = g[i][j].rgbtGreen;
            image[i][j].rgbtBlue = g[i][j].rgbtBlue;
        }
    }
    return;
}
