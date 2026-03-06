#include <stdio.h>

struct Sensor {
    int id;
    float temperatura;
};

int main() {

    struct Sensor s1;

    s1.id = 10;
    s1.temperatura = 26.5;

    printf("ID: %d\n", s1.id);
    printf("Temp: %.2f\n", s1.temperatura);

}

