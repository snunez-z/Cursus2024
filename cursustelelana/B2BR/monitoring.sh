# ARCH La arquitectura de tu sistema operativo y su versión de kernel. uname es un comando de informacion sobre el sistema 
arch=$(uname -a)

# CPU PHYSICAL El número de núcleos físicos e informacion del procesador (tipo,marca ...)
# Miro en Fichero (/proc....) toda la informacion relativa a physical id y como me va a salir uan linea por cada nucleo fisico lo que haga paso esa salida al wc que lo que me hace es contar las lineas.
cpuf=$(grep "physical id" /proc/cpuinfo | sort -u | wc -l) # word count - l (cuenta lineas) 

# CPU VIRTUAL  El número de núcleos virtuales- los subprocesos
cpuv=$(grep "processor" /proc/cpuinfo | wc -l)
 
# RAM La memoria RAM disponible actualmente en tu servidor y su porcentaje de uso . Para filtar la info e imprimir solo unos datos concreto usamos awk
ram_total=$(free --mega | awk '$1 == "Mem:" {print $2}') 
ram_available=$(free --mega | awk '$1 == "Mem:" {print $7}')
ram_percent=$(free --mega | awk '$1 == "Mem:" {printf("%.2f"), $3/$2*100}')

# DISK La memoria disco duro disponible actualmente en tu servidor y su utilización como un %.
disk_total=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_t += $2} END {printf ("%.1fGb\n"), disk_t/1024}') # total se queda con los dev, excluye los boot suma todo lo que haya en la columna 2 
disk_ava=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_u += $3} END {print disk_u/1000}') # Ver memoria usada, comando df (disk file sytem)
disk_percent=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_u += $3} {disk_t+= $2} END {printf("%d"), disk_u/disk_t*100}') # porcentaje de la memoria usada 

# CPU LOAD El porcentaje actual de uso de tus núcleos.
cpul=$(vmstat 1 2 | tail -1 | awk '{printf $15}')
cpu_op=$(expr 100 - $cpul)
cpu_fin=$(printf "%.1f" $cpu_op)

# LAST BOOT La fecha y hora del último reinicio.
lb=$(who -b | awk '$1 == "system" {print $3 " " $4}')

# LVM USE  Si LVM está activo o no.
lvmu=$(if [ $(lsblk | grep "lvm" | wc -l) -gt 0 ]; then echo yes; else echo no; fi)

# TCP CONNEXIONS El número de conexiones activas.
tcpc=$(ss -ta | grep ESTAB | wc -l)

# USER LOG El número de usuarios del servidor.
ulog=$(getent passwd | grep /bin | wc -l)

# NETWORK la dirección IPv4 de tu servidor y su MAC (Media Access Control)
ip=$(hostname -I)
mac=$(ip link | grep "link/ether" | awk '{print $2}')

# SUDO El número de comandos ejecutados con sudo.
cmnd=$(journalctl _COMM=sudo | grep COMMAND | wc -l)

wall "	Architecture: $arch
	CPU physical: $cpuf
	vCPU: $cpuv
	Memory Available: $ram_available/${ram_total}MB ($ram_percent% used)
	Disk Available: $disk_ava/${disk_total} ($disk_percent% used)
	CPU load: $cpu_fin%
	Last boot: $lb
	LVM use: $lvmu
	Connections TCP: $tcpc ESTABLISHED
	User log: $ulog
	Network: IP $ip ($mac)
	Sudo: $cmnd cmd"

