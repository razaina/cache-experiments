#! /bin/sh

FIC_RESULTATS="resultats/sequentiels.txt"
FIC_DATA_READ="resultats/read-sequentiels.txt"
FIC_DATA_WRITE="resultats/write-sequentiels.txt"
FIC_GRAPHIQUE="resultats/graph-sequentiel.png"

#> "$FIC_RESULTATS"

#N=1
#P=$((32768))

#taskset -pc 0 $$

#while [ "$P" -ge 1 ]
#do
        #echo "$N / $P " >&2
        #echo "taille bloc : $N, nb_cycles : $P" >> "$FIC_RESULTATS"
        #./cache-exp-1 "$N" "$P" >> "$FIC_RESULTATS"
        #N=$((N<<1))
        #P=$((P>>1))
#done
#grep ecriture < "$FIC_RESULTATS" | awk '{print $6}' > "$FIC_DATA_WRITE"
#grep lecture  < "$FIC_RESULTATS" | awk '{print $6}' > "$FIC_DATA_READ"


gnuplot <<-EOF
    reset
    set terminal png size 1200,800
    set grid
    set mxtics 10 
    set output '$FIC_GRAPHIQUE'
    set multiplot layout 2,1
    set xlabel "log2(nombre de blocs)'
    set ylabel 'duree boucle (ns)
    set style function linespoints
    set format x "2^%g"
    plot "$FIC_DATA_WRITE" w lp lt -1 pi -1 pt 6 lc rgb '#FF0000'
    plot "$FIC_DATA_READ" w lp lt -1 pi -1 pt 17 lc rgb '#0000FF'
    unset multiplot
EOF
