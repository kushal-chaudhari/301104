#include <graphics.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int midx, midy, r = 10;
    midx = getmaxx() / 2;

    // Loop until the radius is 50
    while (r <= 50)
    {
        // Clear the graphics window
        cleardevice();

        // Draw a house with a triangular roof
        setcolor(WHITE);
        line(0, 310, 160, 150);
        line(160, 150, 320, 310);
        line(320, 310, 480, 150);
        line(480, 150, 640, 310);
        line(0, 310, 640, 310);

        // Draw an animated bouncing ball using an arc
        arc(midx, 310, 225, 133, r);

        // Fill the ball with color using flood-fill
        floodfill(midx, 300, 15);

        // Add additional details if the radius is greater than 20
        if (r > 20)
        {
            setcolor(7); // Set color for the door
            floodfill(2, 2, 15);       // Flood-fill the door
            setcolor(6); // Set color for windows
            floodfill(150, 250, 15);   // Flood-fill the left window
            floodfill(550, 250, 15);   // Flood-fill the right window
            setcolor(2); // Set color for the ground
            floodfill(2, 450, 15);     // Flood-fill the ground
        }

        // Introduce a delay to control the animation speed
        delay(50);

        // Increase the radius for the next frame
        r += 2;
    }

    // Wait for a key press before closing the graphics window
    getch();
    closegraph();

    return 0;
}