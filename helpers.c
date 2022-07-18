#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            double avgF = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0;
            int avg = (int)avgF;
            if (avgF - avg >= 0.5)
            {
                avg++;
            }
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtRed = avg;
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
            float sepRedF = 0.393f * image[i][j].rgbtRed + 0.769f * image[i][j].rgbtGreen + 0.189f * image[i][j].rgbtBlue;
            float sepGreenF = 0.349f * image[i][j].rgbtRed + 0.686f * image[i][j].rgbtGreen + 0.168f * image[i][j].rgbtBlue;
            float sepBlueF = 0.272f * image[i][j].rgbtRed + 0.534f * image[i][j].rgbtGreen + 0.131f * image[i][j].rgbtBlue;
            int sepRed = sepRedF;
            int sepGreen = sepGreenF;
            int sepBlue = sepBlueF;

            if (sepRedF - sepRed >= 0.5) //rounding off to the nearest integer
            {
                sepRed++;
            }


            if (sepGreenF - sepGreen >= 0.5)
            {
                sepGreen++;
            }

            if (sepBlueF - sepBlue >= 0.5)
            {
                sepBlue++;
            }
            if (sepRed > 255) // checking if it is in limits
            {
                sepRed = 255; // keeping it within limits
            }
            if (sepBlue > 255)
            {
                sepBlue = 255;
            }
            if (sepGreen > 255)
            {
                sepGreen = 255;
            }
            // Let's update the pixel colors:
            image[i][j].rgbtBlue = sepBlue;
            image[i][j].rgbtGreen = sepGreen;
            image[i][j].rgbtRed = sepRed;
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
            // Let's swap laterally opposite pixels
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // At first, I'll have to create a copy
    RGBTRIPLE imageCopy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            imageCopy[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // For each pixel
            int sumR, sumG, sumB; // stores sum of RGB values of pixels in the 9 boxes for each pixel
            sumR = sumG = sumB = 0;
            int k = 0;
            int r0 = i - 1, c0 = j - 1; // starting pixel to sum up color values
            int r_m, c_n;
            for (int m = 0; m < 3; m++)
            {
                for (int n = 0; n < 3; n++)
                {
                    r_m = r0 + m;
                    c_n = c0 + n;
                    if (r_m >= 0 && c_n >= 0 && r_m < height && c_n < width)
                    {
                        k++;
                        sumR += imageCopy[r_m][c_n].rgbtRed;
                        sumG += imageCopy[r_m][c_n].rgbtGreen;
                        sumB += imageCopy[r_m][c_n].rgbtBlue;
                    }
                }
            }
            double avgR_f = sumR / (double)k;   // finding averages
            double avgG_f = sumG / (double)k;
            double avgB_f = sumB / (double)k;

            int avgR = avgR_f;  // storing integer parts
            int avgG = avgG_f;
            int avgB = avgB_f;

            if (avgR_f - avgR >= 0.5) // Rounding off values
            {
                avgR++;
            }
            if (avgG_f - avgG >= 0.5)
            {
                avgG++;
            }
            if (avgB_f - avgB >= 0.5)
            {
                avgB++;
            }
            image[i][j].rgbtBlue = avgB;    //updating pixel colors
            image[i][j].rgbtGreen = avgG;
            image[i][j].rgbtRed = avgR;
        }
    }
    return;
}
