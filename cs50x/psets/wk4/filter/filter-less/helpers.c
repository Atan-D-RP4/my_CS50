#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Iterate over each row of pixels
    for (int i = 0; i < height; i++)
    {
        // Iterate over each column of pixels
        for (int j = 0; j < width; j++)
        {
            int gray = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            // Change color of pixel
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = gray;
        }
    }
    return;
}



// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Iterate over each row of pixels
    for (int i = 0; i < height; i++)
    {
        // Iterate over each column of pixels
        for (int j = 0; j < width; j++)
        {
            int sepiaRed   = (round((.393 * image[i][j].rgbtRed) + (.769 * image[i][j].rgbtGreen) + (.189 * image[i][j].rgbtBlue)));
            int sepiaGreen = (round((.349 * image[i][j].rgbtRed) + (.686 * image[i][j].rgbtGreen) + (.168 * image[i][j].rgbtBlue)));
            int sepiaBlue  = (round((.272 * image[i][j].rgbtRed) + (.534 * image[i][j].rgbtGreen) + (.131 * image[i][j].rgbtBlue)));

            image[i][j].rgbtRed = (sepiaRed > 255 ? 255 : sepiaRed);
            image[i][j].rgbtGreen = (sepiaGreen > 255 ? 255 : sepiaGreen);
            image[i][j].rgbtBlue = (sepiaBlue > 255 ? 255 : sepiaBlue);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Iterate over each row of pixels
    for (int i = 0; i < height; i++)
    {
        // Iterate over each column of pixels
        for (int j = 0; j < width / 2; j++)
        {

            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][(width - 1) - j];
            image[i][(width - 1) - j] = temp;

        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    // Create a copy of the image

    // Iterate over each row of pixels
    for (int i = 0; i < height; i++)
    {
        // Iterate over each column of pixels
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        // Iterate over each column of pixels
        for (int j = 0; j < width; j++)
        {
            int total_red   = 0;
            int total_green = 0;
            int total_blue  = 0;
            int neighbors   = 0;

            // Iterating over each neighbor of the pixel
            for (int k = i - 1; k <= i + 1; k++)
            {
                for (int l = j - 1; l <= j + 1; l++)
                {
                    // Check if neighbor is within image boundaries
                    if (k >= 0 && k < height && l >= 0 && l < width)
                    {
                        total_red   += copy[k][l].rgbtRed;
                        total_green += copy[k][l].rgbtGreen;
                        total_blue  += copy[k][l].rgbtBlue;
                        neighbors++;
                    }
                }
            }

            image[i][j].rgbtRed     = round((float)total_red / neighbors);
            image[i][j].rgbtGreen   = round((float)total_green / neighbors);
            image[i][j].rgbtBlue    = round((float)total_blue / neighbors);
        }
    }
    return;
}
