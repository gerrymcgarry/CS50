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

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float red = image[i][j].rgbtRed;
            float green = image[i][j].rgbtGreen;
            float blue = image[i][j].rgbtBlue;
            int sepiaRed = round((red * 0.393) + (green * 0.769) + (blue * 0.189));
            int sepiaGreen = round((red * 0.349) + (green * 0.686) + (blue * 0.168));
            int sepiaBlue = round((red * 0.272) + (green * 0.534) + (blue * 0.131));

            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaRed = 255;
            }
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
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
