struct RGB
{
public:
    // 0 ~ 1
    // Red, Green, Blue
    float r, g, b;

    RGB(float r, float g, float b)
    {
        this->r = r;
        this->g = g;
        this->b = b;
    }

    float Min()
    {
        return min(r, min(g, b));
    }

    float Max()
    {
        return max(r, max(g, b));
    }
};

class HSV
{
public:
    // 0 ~ 360
    // Hue
    int H;
    // 0 ~ 1
    // Saturation, Value
    float S, V;

    HSV(int H, float S, float V)
    {
        this->H = H;
        this->S = S;
        this->V = V;
    }
};

HSV ConvertToHSV(RGB color)
{
    float Cmax = color.Max();
    float Cmin = color.Min();
    float Delta = Cmax - Cmin;
    
    int H;
    float S, V = Cmax;
    S = (Cmax != 0) ? Delta / Cmax : 0;

    if      (Delta == 0)
        H = 0;
    else if (color.r == Cmax)
        H = (color.g - color.b) / Delta;
    else if (color.g == Cmax)
        H = (color.b - color.r) / Delta + 2;
    else
        H = (color.r - color.g) / Delta + 4;

    H *= 60.0;
    if(H < 0)
        H += 360;

    return HSV(H, S, V);
}
