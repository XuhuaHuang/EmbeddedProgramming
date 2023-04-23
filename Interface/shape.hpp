__interface IShape
{
    void   Draw() abstract;
    double GetArea() abstract;
};

ref class Circle : public IShape
{
public:
    void Draw() override
    {
        // Implementation of Draw for Circle
    }

    double GetArea() override
    {
        // Implementation of GetArea for Circle
        return 3.14 * radius * radius;
    }

private:
    double radius;
};
