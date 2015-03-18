#! /bin/sh

FIC_RESULTATS="resultats/seq.txt"
FIC_DATA_READ="resultats/read-seq.txt"
FIC_DATA_WRITE="resultats/write-seq.txt"
FIC_GRAPHIQUE="resultats/graph-seq.png"

#FIC_RESULTATS="resultats/random.txt"
#FIC_DATA_READ="resultats/read-rand.txt"
#FIC_DATA_WRITE="resultats/write-rand.txt"
#FIC_GRAPHIQUE="resultats/graph-rand.png"
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
    set style line 1 linetype 1 pointtype 6 linewidth 2 linecolor 6 pointsize 2
    set style line 2 linetype 1 pointtype 6 linewidth 2 linecolor 7 pointsize 2
    set terminal png transparent nocrop enhanced truecolor size 800,400
    set mxtics 10 
    set output '$FIC_GRAPHIQUE'
    set multiplot 
    set title "Random reads"
    set grid

    set xlabel "Working set size (bytes)"
    set ylabel 'Timing (ns)'
    set format x "2^{%g}"
    set arrow from 13,2 to 13,6.5 nohead lc rgb 'blue'
    set arrow from 17,2 to 17,6.5 nohead lc rgb 'red'
    plot "$FIC_DATA_READ" w lp lt -1 pi -1 pt 6 lc rgb '#000000' notitle 

    unset multiplot
EOF
    #plot "$FIC_DATA_READ" w lp lt -1 pi -1 pt 17 lc rgb '#0000FF' t "Sequential writes"
    #set arrow from 13,3.5 to 13,8 nohead lc rgb 'blue'
