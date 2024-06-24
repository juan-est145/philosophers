# Philosophers
A repository containing the philosophers project of 42 Malaga. The philosophers project takes a number of philosophers, each one of them as a thread and a time to eat, sleep and die and a last optional parameter wich states how many times must they eat. The aim of this project is to create several threads and avoid deadlocks when these threads try to access some resources in a certain span of time. It is based on the famous problem designed by Edsger Dijkstra

This project is meant to be run on MacOS, but it should work too on Linux, although not as efficently. In the subject pdf you can find all of the details of the program and how to use it.

If you are a fellow student of 42, do not just copy this project without understanding, use it to learn instead.

## Run

Clone the project

```bash
  git clone https://github.com/juan-est145/philosophers.git
```

Go to the project directory

```bash
  cd philosophers
```

Compile the project

```bash
  make
```
Run the executable

```bash
  ./philosophers (nº of philos) (time to die in ms) (time to eat in ms) (time to sleep in ms) (nº of times each philo must eat. Optional argument)
```
To delete the .o files and the executable

```bash
  make fclean
```