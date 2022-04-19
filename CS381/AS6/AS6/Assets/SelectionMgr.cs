using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SelectionMgr : MonoBehaviour
{
    public static SelectionMgr inst;
    public Entity381 selectedEntity;
    public Vector3 Intersection_Point = Vector3.zero;
    public List<int> IDs = new List<int>();
    public int selectedEntityIndex = 0;
    public int closestEntity = 0;

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
        if (Input.GetMouseButtonDown(0))
        {
            Click();
        }
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

    void Click()
    {
        RaycastHit raycastInfo;
        IDs.Clear();
        if (Physics.Raycast(Camera.main.ScreenPointToRay(Input.mousePosition), out raycastInfo, Mathf.Infinity))
        {
            Intersection_Point = raycastInfo.point;

            closestEntity = findClosestEntity(raycastInfo.point);
            SelectClosestEntity(closestEntity);

        }

    }

    public int findClosestEntity(Vector3 Intersection_Point)
    {
        int ID = selectedEntityIndex;
        float _min = 6;
        for (int i = 0; i < EntityMgr.inst.entities.Count; i++)
        {
            if (Vector3.Distance(Intersection_Point, EntityMgr.inst.entities[i].position) < _min)
            {
                _min = Vector3.Distance(Intersection_Point, EntityMgr.inst.entities[i].position);
                ID = i;
            }
        }
        return ID;
    }

    public void SelectClosestEntity(int id)
    {
        selectedEntity = EntityMgr.inst.entities[id];
        UnselectAll();
        selectedEntity.isSelected = true;
    }
}
