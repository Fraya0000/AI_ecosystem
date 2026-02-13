enum class gameState
{
    Morning,
    Day,
    Evening
};

class gameTime
{
private:
    float time;
    gameState state;

public:
    gameTime();
    ~gameTime();

    void update(float deltaTime);

    float getTime() const
    {
        return time;
    }

    gameState getState() const
    {
        return state;
    }
};