#include <math.h>
#include <assert.h>

#include "part1.h"

// Set the x and y fields of the point structure pointed to by pt
// to the x and y values passed in as arguments.  The point structure
// is defined in the part1.h header file.
//
// This should only take a couple of lines.
void set_point(struct point* pt, double x, double y)
{
    pt->x = x;
    pt->y = y;

}

// Create and return a new point with x and y
// initialized to x and y
//
// This should only take a couple of lines.
struct point* create_point(double x, double y)
{
    struct point* pt2;
    pt2->x = x;
    pt2->y = y;

    return pt2;

}

// Compute the planar distance between two points. Recall that the
// distance between two points in a plane is computed as follows. Label
// the two points (x1, y1) and (x2, y2).  Let dx be the difference
// between x1 and x2 and dy be the difference between y1 and y2. The
// distance between the two points is the square root of the sum of dx
// squared plus dy squared.
//
// Hint: Use the sqrt function from math.h.  You do not need to use
// the pow function; x * x is sufficient to square a variable.
double point_dist(struct point *pt1, struct point *pt2)
{
    double distance=0;

    double ptX = pt1->x;
    double ptY = pt1->y;

    double pt2X = pt2->x;
    double pt2Y = pt2->y;

    double dx = ptX - pt2X;
    double dy = ptY - pt2Y;

    distance=sqrt((dx*dx)+(dy*dy));

    return distance;
}
