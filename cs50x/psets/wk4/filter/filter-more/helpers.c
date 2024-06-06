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

int cap(int a)
{
    return (a > 255 ? 255 : a);
}

RGBTRIPLE get_edge_pixel(int i, int j, int height, int width, RGBTRIPLE copy[height][width])
{
    // Define Sobel Operators kernels
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    int Gx_Red   = 0, Gy_Red   = 0;
    int Gx_Green = 0, Gy_Green = 0;
    int Gx_Blue  = 0, Gy_Blue  = 0;

    // Iterate over each row pixels within 1 pixel of target pixel(including diagonals)
    for (int k = i - 1; k <= i + 1; k++)
    {
        // Iterate over each column pixels within 1 pixel of target pixel(including diagonals)
        for (int l = j - 1; l <= j + 1; l++)
        {
            // Check if target pixel is not on the sides of the image
            if (k >= 0 && k < height && l >= 0 && l < width)
            {
                // Compute Weighted Sum horizontally
                Gx_Red   += copy[k][l].rgbtRed   * Gx[k - i + 1][l - j + 1];
                Gx_Green += copy[k][l].rgbtGreen * Gx[k - i + 1][l - j + 1];
                Gx_Blue  += copy[k][l].rgbtBlue  * Gx[k - i + 1][l - j + 1];

                // Compute Weighted Sum vertically
                Gy_Red   += copy[k][l].rgbtRed   * Gy[k - i + 1][l - j + 1];
                Gy_Green += copy[k][l].rgbtGreen * Gy[k - i + 1][l - j + 1];
                Gy_Blue  += copy[k][l].rgbtBlue  * Gy[k - i + 1][l - j + 1];
            }
        }
    }

    // Applying Sobel Filter algorithm for the pixel
    int G2_Red   = (Gx_Red * Gx_Red)     + (Gy_Red * Gy_Red);
    int G2_Green = (Gx_Green * Gx_Green) + (Gy_Green * Gy_Green);
    int G2_Blue  = (Gx_Blue * Gx_Blue)   + (Gy_Blue * Gy_Blue);

    // Defining the edged pixel
    RGBTRIPLE edged;
    edged.rgbtRed     = cap(round(sqrt((float)G2_Red)));
    edged.rgbtGreen   = cap(round(sqrt((float)G2_Green)));
    edged.rgbtBlue    = cap(round(sqrt((float)G2_Blue)));

    return edged;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
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
        for (int j = 0; j < width; j++)
        {
            image[i][j] = get_edge_pixel(i, j, height, width, copy);
        }
    }
    return;
}
