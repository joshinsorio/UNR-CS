using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SelectionMgr : MonoBehaviour
{
    public static SelectionMgr inst;
    public Entity381 selectedEntity;
    public int selectedEntityIndex = 0;

    //Declare instance
    public void Awake()
    {
        inst = this;
    }


    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        //Selection input
        if (Input.GetKeyUp(KeyCode.Tab))
            SelectNextEntity();
    }

    void SelectNextEntity()
    {
        selectedEntityIndex = (selectedEntityIndex >= EntityMgr.inst.entities.Count - 1 ? 0 : selectedEntityIndex + 1);
        selectedEntity = EntityMgr.inst.entities[selectedEntityIndex];
        UnselectAll();
        selectedEntity.isSelected = true;
    }

    void UnselectAll()
    {
       foreach (Entity381 ent in EntityMgr.inst.entities)
        ent.isSelected = false;
    }
}
