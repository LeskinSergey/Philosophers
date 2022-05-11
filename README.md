# Philosophers
```bash
This project is a solution to the classic diner philosophers problem.
The question of the task is to develop a behavior model (parallel algorithm) in which none of the philosophers will starve, that is, they will forever alternate between eating and thinking.
```
# start
```bash
make 

./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]
```
```bash
◦ number_of_philosophers: The number of philosophers and also the number
  of forks.
◦ time_to_die (in milliseconds): If a philosopher didn’t start eating time_to_die
  milliseconds since the beginning of their last meal or the beginning of the simulation, they die.
◦ time_to_eat (in milliseconds): The time it takes for a philosopher to eat.
  During that time, they will need to hold two forks.
◦ time_to_sleep (in milliseconds): The time a philosopher will spend sleeping.
◦ number_of_times_each_philosopher_must_eat (optional argument): If all
  philosophers have eaten at least number_of_times_each_philosopher_must_eat
  times, the simulation stops. If not specified, the simulation stops when a
  philosopher dies.
  ```
