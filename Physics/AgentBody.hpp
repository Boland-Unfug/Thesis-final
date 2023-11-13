class AgentBody
{
public:
    int x_position;
    int y_position;
    int previous_x_position;
    int previous_y_position;
    int x_acceleration;
    int y_acceleration;

    int id;

    void update_position()
    {
        const int x_velocity = x_position - previous_x_position;
        const int y_velocity = y_position - previous_y_position;

        previous_x_position = x_position;
        previous_y_position = y_position;

        x_position = x_position + x_velocity + x_acceleration;
        y_position = y_position + y_velocity + y_acceleration;
    }

    void set_x_position(int x_position)
    {
        this->x_position = x_position;
    }

    void set_y_position(int y_position)
    {
        this->y_position = y_position;
    }

    void set_previous_x_position(int previous_x_position)
    {
        this->previous_x_position = previous_x_position;
    }

    void set_previous_y_position(int previous_y_position)
    {
        this->previous_y_position = previous_y_position;
    }

    void set_x_acceleration(int x_acceleration)
    {
        this->x_acceleration = x_acceleration;
    }

    void set_y_acceleration(int y_acceleration)
    {
        this->y_acceleration = y_acceleration;
    }

    int get_x_position()
    {
        return x_position;
    }

    int get_y_position()
    {
        return y_position;
    }

    int get_previous_x_position()
    {
        return previous_x_position;
    }

    int get_previous_y_position()
    {
        return previous_y_position;
    }

    int get_x_acceleration()
    {
        return x_acceleration;
    }

    int get_y_acceleration()
    {
        return y_acceleration;
    }

    int get_id()
    {
        return id;
    }

};