#include "helpers.h"
#include <math.h>
#include <stdbool.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float x = ( image[i][j].rgbtBlue + image[i][j].rgbtRed + image[i][j].rgbtGreen ) / 3.0;

            image[i][j].rgbtBlue = x;
            image[i][j].rgbtRed = x;
            image[i][j].rgbtGreen = x;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    //sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue
    //sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue
    //sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = ( .189 *image[i][j].rgbtBlue + .393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen ) ;
            image[i][j].rgbtBlue = ( .131 *image[i][j].rgbtBlue + .272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen ) ;
            image[i][j].rgbtGreen = ( .168 *image[i][j].rgbtBlue + .349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen ) ;

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i =0; i < height; i++)
    {
        if (width % 2 == 0)
        {
            int n = width/2;
            for (int j = 0; j < n; j++)
            {
                RGBTRIPLE temp = image[i][j];
                image[i][j] = image[i][ width - 1 - j];
                image[i][ width - 1 - j] = temp;
            }
        }
        else
        {
            int n = (width - 1)/2;
            for (int j = 0; j < n; j++)
            {
                RGBTRIPLE temp = image[i][j];
                image[i][j] = image[i][ width - 1 - j];
                image[i][ width - 1 - j] = temp;
            }
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int redSum = 0, greenSum = 0, blueSum = 0;
            int count = 0;

            // The blurring kernel
            for (int k = -1; k <= 1; k++)
            {
                for (int l = -1; l <= 1; l++)
                {
                    int newI = i + k;
                    int newJ = j + l;

                    if (newI >= 0 && newI < height && newJ >= 0 && newJ < width)
                    {
                        redSum += image[newI][newJ].rgbtRed;
                        greenSum += image[newI][newJ].rgbtGreen;
                        blueSum += image[newI][newJ].rgbtBlue;
                        count++;
                    }
                }
            }

            temp[i][j].rgbtRed = round((float)redSum / count);
            temp[i][j].rgbtGreen = round((float)greenSum / count);
            temp[i][j].rgbtBlue = round((float)blueSum / count);
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
}

