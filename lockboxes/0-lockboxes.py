#!/usr/bin/python3
"""
Ce script permet de résoudre le challenge lockboxes
"""

def canUnlockAll(boxes):
    """
    The function `canUnlockAll` checks if all the boxes in the given list can
    be unlocked by finding the corresponding keys in other boxes.
    :param boxes: The parameter "boxes" is a list of lists. Each inner list
    represents a box, and contains integers that represent the keys inside
    that box. The index of each inner list represents the box number
    :return: a boolean value indicating whether all the boxes can be unlocked
    or not.
    """

    keys = set([0])  # on a toujours la clé 0 au début
    box_open = set()

    while True:
        # Boucle infinie pour refaire le tour
        # de toute nos boxes
        new_keys_found = False

        # on commence par parcourir chaque boite individuellement
        # dans l'ordre
        for index, box in enumerate(boxes):
            # Si on a la clé qui ouvre la boite à l'index
            # Et qu'on ne la jamais ouvert
            if index in keys and index not in box_open:
                # On ajoute la boite qu'on vient d'ouvrir
                box_open.add(index)
                # On ouvre la boite pour découvrir les clés dedans
                for key in box:
                    # Et on ajoute les clés à notre trousseau
                    keys.add(key)
                    new_keys_found = True
                    # on a trouvé une clé donc on va refaire le tour

        if not new_keys_found:
            break

    # On renvoi True ou False si la somme des boites
    # ouverte est égale à la somme des boites données
    return len(box_open) == len(boxes)
