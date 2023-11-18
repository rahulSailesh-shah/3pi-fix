

void procedure1(int arg)
{
    int checkArg;
    pthread_mutex_lock(&lock_a);
    checkArg = (a == arg);
    pthread_mutex_unlock(&lock_a);

    if (checkArg)
    {
        pthread_mutex_lock(&lock_b);
        pthread_mutex_lock(&lock_a);
        if (a == arg)
        {
            procedure2(arg);
        }
        pthread_mutex_unlock(&lock_a);
        pthread_mutex_unlock(&lock_b);
    }
}

void proc1()
{
    pthread_mutex_lock(&lock_a);
    a = 1;
    pthread_cond_wait(&go, &lock a);
    pthread_mutex_unlock(&lock_a);
    proc3b();
}

void proc2()
{
    pthread_mutex_lock(&lock_a);
    a = 0;
    pthread_cond_signal(&go);
    pthread_mutex_unlock(&lock_a);
    proc3b();
}