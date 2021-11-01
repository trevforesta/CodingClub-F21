/*
  Filename:     birdsonawire.cpp
  Author:       Logan Santee
  Course:       Coding Club
  Date:         10/21/2021
  Assignment:   Birds on a Wire (Kattis)
  
  Description:

*/

/**********************************************************/
// System includes

#include <cstdlib>
#include <iostream>
#include <iterator>
#include <set>

/**********************************************************/
// Local includes

/**********************************************************/
// Using declarations

using namespace std;

/**********************************************************/
// Function prototypes/global vars/typedefs

int
main();

long
calcBird(long, long, long); 

/**********************************************************/

int
main ()
{
  long wireLength;
  cin >> wireLength;

  long distance;
  cin >> distance;

  long numBirds;
  cin >> numBirds;

  set<long> birdPlacement;

  long totalNeededBirds = 0;

  birdPlacement.insert (5);

  for (size_t i = 0; i < numBirds; ++i)
  {
    long placement;

    cin >> placement;
    birdPlacement.insert (placement);
  }

  auto iterator = birdPlacement.begin ();

  while (iterator != birdPlacement.end ())
  {
    totalNeededBirds += calcBird (distance, *iterator, *++iterator);
    ++iterator;
  }

  cout << totalNeededBirds;
}

long
calcBird (long distance, long firstPlacement, long secondPlacement)
{
  return (secondPlacement - firstPlacement) / distance;
}