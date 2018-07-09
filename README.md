# Blockchain_Project

## Documentación

El presente programa es una recreación del sistema Blockchain en C++.

Capacidades:

1 - Creación de usuarios en la red mediante nodos.

2 - Interconexión de usuarios (simulación P2P-BLockchain)

3 - Visualización de un menú con las siguientes opciones:

    MENU - APUESTAS
    VER HISTORIAL: retorna la cadena sincronizada
    REALIZAR APUESTA: realiza una transacción
    VER BALANCE: revisa la cadena para hacer un balance de las transacciones (criptomoneda)
    GUARDAR ARCHIVO: traslada la cadena a un archivo .txt
    VERIFICAR CADENA (COMING SOON): verifica si el archivo anterior ha sido alterado (validación textual)
    
Métodos - Capacidades:

  Controller new_user("Usuario1", 100) -1
  
  new_user.display_menu()  -3
  
  Controller new_user2("Usuario2", 100)  -1
  
  new_user.connect_node(new_user2) -2
  
  new_user2 + new_user -2
