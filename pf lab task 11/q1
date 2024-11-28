#include <stdio.h>


struct rectangle {
    float length;
    float width;
};

int check(struct rectangle rect) {
    if (rect.length>0.0 && rect.length<20.0 && rect.width>0.0 && rect.width<20.0) {
        return 1;
    } else{
        return 0;
    }
}

float perimeter(struct rectangle rect) {
    return 2*(rect.length+rect.width);
}

float area(struct rectangle rect) {
    return rect.length*rect.width;
}

int main() {
    struct rectangle rect;
    
    printf("Enter length of the rectangle: ");
    scanf("%f", &rect.length);
    printf("Enter width of the rectangle: ");
    scanf("%f", &rect.width);

    if (check(rect)) {
        printf("Perimeter of the rectangle: %.2f\n", perimeter(rect));
        printf("Area of the rectangle: %.2f\n", area(rect));
    } else {
        printf("Error: Length and width must be greater than 0.0 and less than 20.0.\n");
    }

    return 0;
}
