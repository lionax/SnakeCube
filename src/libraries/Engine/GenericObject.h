class GenericObject {
public:
    template<Class T>    
    virtual update(SensorService *sensor, SystemService *system, T *objects);
    virtual draw(DisplayService *display);
    virtual init(SensorService *sensor, T *objects);
}