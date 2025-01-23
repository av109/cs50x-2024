#include "helpers.h"
#include <math.h>

int cap255(int color);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Take average of red, green, and blue
            int avg =
                round((image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen) / 3.0);
            // Update pixel values
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtRed = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Compute sepia values
            int sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen +
                                 .189 * image[i][j].rgbtBlue);
            int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen +
                                   .168 * image[i][j].rgbtBlue);
            int sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen +
                                  .131 * image[i][j].rgbtBlue);

            sepiaRed = cap255(sepiaRed);
            sepiaGreen = cap255(sepiaGreen);
            sepiaBlue = cap255(sepiaBlue);

            // Update pixel with sepia values
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
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            // Swap pixels
            RGBTRIPLE temp;
            temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of image
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
            // Here we'll calculate the blur for each pixel
            int counter = 0;
            int redSum = 0, greenSum = 0, blueSum = 0;

            // Loop through 3x3 grid
            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    // Calculate current position
                    int newi = i + di;
                    int newj = j + dj;

                    // Check if position is valid
                    if (newi >= 0 && newi < height && newj >= 0 && newj < width)
                    {
                        redSum += copy[newi][newj].rgbtRed;
                        greenSum += copy[newi][newj].rgbtGreen;
                        blueSum += copy[newi][newj].rgbtBlue;
                        counter++;
                    }
                }
            }

            // Calculate averages and update image
            image[i][j].rgbtRed = round((float) redSum / counter);
            image[i][j].rgbtGreen = round((float) greenSum / counter);
            image[i][j].rgbtBlue = round((float) blueSum / counter);
        }
    }

    return;
}

int cap255(int color)
{
    if (color > 255)
    {
        return 255;
    }
    else
    {
        return color;
    }
}
