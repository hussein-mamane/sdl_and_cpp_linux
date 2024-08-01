#include <SDL2/SDL.h>
#include <math.h>

// Function to calculate the distance between the centers of two SDL_Rects
double distanceBetweenCenters(SDL_Rect rect1, SDL_Rect rect2) {
    // Calculate the center points of the two rectangles
    SDL_Point center1;
    center1.x = rect1.x + rect1.w / 2;
    center1.y = rect1.y + rect1.h / 2;

    SDL_Point center2;
    center2.x = rect2.x + rect2.w / 2;
    center2.y = rect2.y + rect2.h / 2;

    // Calculate the distance between the center points
    double distance = sqrt(pow(center2.x - center1.x, 2) + pow(center2.y - center1.y, 2));

    return distance;
}



#include <vector>

// Your function to get points between centers
std::vector<SDL_Point> getPointsBetweenCenters(SDL_Rect rect1, SDL_Rect rect2);

int main() {
    SDL_Rect rect1 = {25, 25, 50, 50};
    SDL_Rect rect2 = {400, 45, 50, 50};

    std::vector<SDL_Point> points = getPointsBetweenCenters(rect1, rect2);

    for (const auto& point : points) {
        printf("Point: (%d, %d)\n", point.x, point.y);
    }

    return 0;
}

std::vector<SDL_Point> getPointsBetweenCenters(SDL_Rect rect1, SDL_Rect rect2) {
    SDL_Point center1;
    center1.x = rect1.x + rect1.w / 2;
    center1.y = rect1.y + rect1.h / 2;

    SDL_Point center2;
    center2.x = (rect2.x + rect2.w) / 2;
    center2.y = (rect2.y + rect2.h) / 2;

    std::vector<SDL_Point> points;

    int x1 = center1.x;
    int y1 = center1.y;
    int x2 = center2.x;
    int y2 = center2.y;

    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    //Step
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1; 
    int err = dx - dy;

    while (true) {
        points.push_back({x1, y1});

        if (x1 == x2 && y1 == y2) break;

        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }

    return points;
}

