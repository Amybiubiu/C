#include <iostream>
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 
#include <time.h> 

// Parametes setting
#define POPSIZE 50 
//population size

#define MAXGENS 10000
//max number of generation
#define NVARS 2
//no of problem variables

#define PXOVER 0.75
//probability of crossover

#define PMUTATION 0.15
//probability of mutation
#define TRUE 1
#define FALSE 0

int generation;

int cur_best;

FILE *galog;

struct genotype

{

    //current generation no.

    //best individual

    //an output file

    double gene[NVARS];

    double fitness;

    double upper[NVARS];

    double lower[NVARS];

    double rfitness;

    double cfitness;

    //a string of variables

    //individual's fitness

    //individual's variables upper bound

    //individual's variables lower bound

    //relative fitness

    //curmulation fitness
};

struct genotype population[POPSIZE + 1];

struct genotype newpopulation[POPSIZE + 1];

//population

//new population replaces the old generation

/*Declaration of procedures used by the gentic algorithm*/

void initialize(void);

double randval(double, double);

void evaluate(void);

void keep_the_best(void);

void elitist(void);

void select(void);

void crossover(void);

void Xover(int, int);

void swap(double *, double *);

void mutate(void);

void report(void);

//********************************************************************************* //Initialization function: Initializes the values of genes within the variables

//bounds. It also initializes all fitness values for each number of the population

//*********************************************************************************

void initialize(void)

{

    int i, j;

    double lbound, ubound;

    for (i = 0; i < NVARS; i++)

    {

        lbound = -5.0;  // 变量范围，左值

        ubound = 5.0;   // 变量范围，右值

        for (j = 0; j < POPSIZE; j++)

        {

            population[j].fitness = 0;

            population[j].rfitness = 0;

            population[j].cfitness = 0;

            population[j].lower[i] = lbound;

            population[j].upper[i] = ubound;

            population[j].gene[i] = randval(population[j].lower[i], population[j].upper[i]);
        }
    }
}

//****************************************************************************

//Random value generator:generates a value within bounds

//****************************************************************************

double randval(double low, double high)

{

    double val;

    val = ((double)(rand() % 10000) / 10000.0) * (high - low) + low;

    return (val);
}

//****************************************************************************

//Evaluation function: evaluate the individual's fitness.

//The current function is:	x[1]^2-x[1]*x[2]+x[3].

//Each time the function is changed, the code has to be recompl

//****************************************************************************

void evaluate(void)

{

    int mem;

    int i;

    double x[NVARS + 1];

    for (mem = 0; mem < POPSIZE; mem++)

    {

        for (i = 0; i < NVARS; i++)

            x[i + 1] = population[mem].gene[i];

        population[mem].fitness = (x[1] * x[1]) - (x[1] * x[2]) + 10;   // 选优函数
    }
}

//****************************************************************************

//Keep_the_best function: This function keeps track of the best member of the

//population.

//****************************************************************************

void keep_the_best()

{

    int mem;

    int i;

    cur_best = 0;

    for (mem = 0; mem < POPSIZE; mem++)

    {

        if (population[mem].fitness > population[POPSIZE].fitness)

        {

            cur_best = mem;

            population[POPSIZE].fitness = population[mem].fitness;
        }
    }

    for (i = 0; i < NVARS; i++)

        population[POPSIZE].gene[i] = population[cur_best].gene[i];
}

//**************************************************************************** 
//Elitist function: The best member of the previous generation is stored as the

//last in the array. If the best individual from the new population is better

//than the best individual from the previous population,then copy the best

//from the new population; else replace the worst individual from the current

//population with the best one from the previous generation.

//****************************************************************************

void elitist()

{

    int i;

    double best, worst;

    int best_mem, worst_mem;

    best = population[0].fitness;

    worst = population[0].fitness;

    for (i = 0; i < POPSIZE; i++)

    {

        if (population[i].fitness > population[i + 1].fitness)

        {

            if (population[i].fitness >= best)

            {

                best = population[i].fitness;

                best_mem = i;
            }

            if (population[i + 1].fitness <= worst)

            {

                worst = population[i + 1].fitness;

                worst_mem = i + 1;
            }
        }

        else

        {

            if (population[i].fitness <= worst)

            {

                worst = population[i].fitness;

                worst_mem = i;
            }

            if (population[i + 1].fitness >= best)

            {

                best = population[i + 1].fitness;

                best_mem = i + 1;
            }
        }
    }

    if (best >= population[POPSIZE].fitness)

    {

        for (i = 0; i < NVARS; i++)

            population[POPSIZE].gene[i] = population[best_mem].gene[i];

        population[POPSIZE].fitness = population[best_mem].fitness;
    }

    else

    {

        for (i = 0; i < NVARS; i++)

            population[worst_mem].gene[i] = population[POPSIZE].gene[i];

        population[worst_mem].fitness = population[POPSIZE].fitness;
    }
}

//****************************************************************************

//Select function: Standard proportional selection for maximization problems

//incorporating elitist model--makes sure that the best member survives.

//****************************************************************************

void select(void)

{

    int mem, i, j;

    double sum = 0;

    double p;

    for (mem = 0; mem < POPSIZE; mem++)

    {

        sum += population[mem].fitness;
    }

    for (mem = 0; mem < POPSIZE; mem++)

    {

        population[mem].rfitness = population[mem].fitness / sum;
    }

    population[0].cfitness = population[0].rfitness;

    for (mem = 1; mem < POPSIZE; mem++)

    {

        population[mem].cfitness = population[mem - 1].cfitness + population[mem].rfitness;
    }

    for (i = 0; i < POPSIZE; i++)

    {

        p = rand() % 1000 / 1000.0;

        if (p < population[0].cfitness)
        {

            newpopulation[i] = population[0];
        }

        else

        {

            for (j = 0; j < POPSIZE; j++)

                if (p >= population[j].cfitness && p < population[j + 1].cfitness)
                {
                    newpopulation[i] = population[j + 1];
                }
        }
    }

    for (i = 0; i < POPSIZE; i++)

        population[i] = newpopulation[i];
}

//****************************************************************************

//Crossover function: selects two parents that take part in the crossover.

//Implements a single point crossover.

//****************************************************************************

void crossover(void)

{

    int mem, one;

    int first = 0;

    double x;

    for (mem = 0; mem < POPSIZE; ++mem)

    {

        x = rand() % 1000 / 1000.0;

        if (x < PXOVER)

        {

            ++first;

            if (first % 2 == 0)

                Xover(one, mem);

            else

                one = mem;
        }
    }
}

//****************************************************************************

//Crossover: performs crossover of the two selected parents.

//****************************************************************************

void Xover(int one, int two)

{

    int i;

    int point;

    if (NVARS > 1)

    {

        if (NVARS == 2)

            point = 1;

        else

            point = (rand() % (NVARS - 1)) + 1;

        for (i = 0; i < point; i++)

            swap(&population[one].gene[i], &population[two].gene[i]);
    }
}

//****************************************************************************

//Swap: A swap procedure that helps in swapping 2 variables.

//****************************************************************************

void swap(double *x, double *y)

{

    double temp;

    temp = *x;

    *x = *y;

    *y = temp;
}

//****************************************************************************

//Mutation function: Random uniform mutation. A variable selected for mutation

//is replaced by a random value between lower and upper bounds of the variable. 
//**************************************************************************** 
void mutate(void)

{

    int i, j;

    double lbound, hbound;

    double x;

    for (i = 0; i < POPSIZE; i++)

        for (j = 0; j < NVARS; j++)

        {

            x = rand() % 1000 / 1000.0;

            if (x < PMUTATION)

            {

                lbound = population[i].lower[j];

                hbound = population[i].upper[j];

                population[i].gene[j] = randval(lbound, hbound);
            }
        }
}

//****************************************************************************

//Report function: Reports progress of the simulation.

//****************************************************************************

void report(void)

{

    int i;

    double best_val;

    double avg;

    double stddev;

    double sum_square;

    double square_sum;

    double sum;

    sum = 0.0;

    sum_square = 0.0;

    for (i = 0; i < POPSIZE; i++)

    {

        sum += population[i].fitness;

        sum_square += population[i].fitness * population[i].fitness;
    }

    avg = sum / (double)POPSIZE;

    square_sum = avg * avg * (double)POPSIZE;
    stddev = sqrt((sum_square - square_sum) / (POPSIZE - 1));
    best_val = population[POPSIZE].fitness;

    fprintf(galog, "\n%5d,	%6.3f,%6.3f,%6.3f\n\n", generation, best_val, avg, stddev);
}

//**************************************************************************** //Main function: Each generation involves selecting the best members, performing //crossover & mutation and then evaluating the resulting population,until the //terminating condition is satisfied.

//****************************************************************************

int main(void)

{

    int i;

    if ((galog = fopen("galog.txt", "w")) == NULL)

    {

        exit(1);
    }

    generation = 0;

    srand(time(NULL));

    fprintf(galog, "number	value fitness deviation\n");

    printf("\n generation best average standard\n");

    initialize();

    evaluate();

    keep_the_best();

    while (generation < MAXGENS)

    {

        generation++;

        select();

        crossover();

        mutate();

        report();

        evaluate();

        elitist();
    }

    fprintf(galog, "\n\n Simulation completed\n");

    fprintf(galog, "\n Best member:\n");

    printf("\n Best member:\n");

    for (i = 0; i < NVARS; i++)

    {

        fprintf(galog, "\n var(%d)=%3.3f", i, population[POPSIZE].gene[i]);
        printf("\n var(%d)=%3.3f", i, population[POPSIZE].gene[i]);
    }

    fprintf(galog, "\n\n Best fitness=%3.3f", population[POPSIZE].fitness);
    fclose(galog);

    printf("\n\n Best fitness=%3.3f\n", population[POPSIZE].fitness);
    printf("Success\n");
    return 0;
}