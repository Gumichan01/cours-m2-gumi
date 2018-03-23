
#Algo boulangerie (Lamport)#

```java
class Boulangerie implements Lock{

    boolean [] flag; int [] label;

    public Boulangerie (int n) {

        flag = new boolean[n];
        label = new LABEL[n];

        for (int i = 0; i < n; i++) {
            flag[i] = false;
        }
    }

    public void lock() {

        int i = ThreadID.get();
        flag[i] = true;
        label[i] = max(label[0], ... , label[n-1]) + 1;
        // loop forever in the while-loop
        while ( (\exists k != i) flag[k] && ( (label[k], k) < (label[i], i) ) );
    }

    public void unlock() {
        flag[ThreadID.get] = false;
    }
}
```

(a, a') < (b, b') <=> a < b /\\ a' < b'

label[] : tableau partagé entre les threads

thread[i] écrit dans label[i]

## Propriétés ##

1. Pas de blocage (interblocage)

- soit A thread telle que (label[A], A) est minimal.

-> A termine la boucle

2. Les threads sont servis "dans l'ordre".
label[A] < label[B]

3. exclusion mutuelle

Supposons que A et B sont en section critique.
Supposons aussi que (label[A], A) < (label[B], B)

B est entreé en SC, donc il a vu :

```
- flag[A] = false -> ABSURDE
- (label[B], B) < (label[A], A)
```
label[A] est croissant -> ABSURDE


**Remarques:**

- utilise 2^n variable partagées (SWMR)
- label peut augmenter indéfiniment.

"timestamp"

** timestamp borné **

Ensemble fini de labels pour chaque sous-ensemble de taille *n*
le sous-ensemble est ordonné et on peut définir un plus petit/grand élément

**Opération:**

 - ocan : tous les threads
 - label : retourne un élément plus grand que tous les autres

 0, 1, 2 ensemble. sous-ensemble de 2 éléments.

 0 < 1 < 2 < 0

 Pour ensemble à 2 éléments,

1. m(0,1), 0 demande -> 2
2. m(0,1), 1 demande -> 1
3. m(0,2), 1 demande -> 0
3. m(1,2), 2 demande -> 0

2)
   1
   |
(0,2)
 |
 0

3)

   1
   |
(0,2)
 |
 0
