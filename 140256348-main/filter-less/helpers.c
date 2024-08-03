#include "helpers.h"
#include <math.h>
#include <stdio.h>
// Convert image to grayscale
int cap(int value)
{
    return value > 255 ? 255 : (value < 0 ? 0 : value);
}

void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {

        for (int j = 0; j < width; j++)
        {

            int avg = round((float) (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = avg;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {

        for (int j = 0; j < width; j++)
        {

            int sepiaRed = cap(round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue));
            int sepiaGreen = cap(round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue));
            int sepiaBlue = cap(round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue));

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {

            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float sumRed = 0, sumGreen = 0, sumBlue = 0;
            int count = 0;

            for (int ni = -1; ni <= 1; ni++)
            {
                for (int nj = -1; nj <= 1; nj++)
                {
                    int ci = i + ni;
                    int cj = j + nj;

                    if (ci >= 0 && ci < height && cj >= 0 && cj < width)
                    {
                        sumRed += copy[ci][cj].rgbtRed;
                        sumGreen += copy[ci][cj].rgbtGreen;
                        sumBlue += copy[ci][cj].rgbtBlue;
                        count++;
                    }
                }
            }
            image[i][j].rgbtRed = round(sumRed / count);
            image[i][j].rgbtGreen = round(sumGreen / count);
            image[i][j].rgbtBlue = round(sumBlue / count);
        }
    }
}
