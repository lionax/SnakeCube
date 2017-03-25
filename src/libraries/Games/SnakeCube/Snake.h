typedef struct Link {
    int x;
    int y;
    struct Link * next;
} Link;

class Snake : public GenericObject {
public:
    init(SensorService *sensor, T *objects);
    update(SensorService *sensor, SystemService *system, T *objects);
    draw(DisplayService *display);
private:
    addHead(int x, int y);
    move(int direction);
    eat(Food *food);
    Link * pHead = NULL;
    Link * pTail = NULL;
    int direction = 0;
}