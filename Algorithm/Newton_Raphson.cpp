// Algorithm used to implement the sqrt function
int Newton_Raphson(int target)
{
    float result = target;
    int integer;

    while(true)
    {
        integer = result;
        result = 0.5 * (result + target / result);
        if(integer == (int)result)
            break;
    }

    return result;
}
