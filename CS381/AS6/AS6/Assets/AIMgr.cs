using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AIMgr : MonoBehaviour
{
    public static AIMgr inst;
    private void Awake()
    {
        inst = this;
    }

    // Start is called before the first frame update
    void Start()
    {
        layerMask = 1 << 9; //LayerMask.GetMask("Ocean");
    }

    public RaycastHit hit;
    public int layerMask;

    // Update is called once per frame
    void Update()
    {
        if (Input.GetMouseButtonDown(1))
        {
            if (Physics.Raycast(Camera.main.ScreenPointToRay(Input.mousePosition), out hit, float.MaxValue, layerMask))
            {
                //Draws yellow lines in scene
                Debug.DrawLine(Camera.main.transform.position, hit.point, Color.yellow, 2); //for debugging
                Vector3 pos = hit.point;
                pos.y = 0;
                Entity381 ent = FindClosestEntInRadius(pos, clickRadius);
                if (ent is null)
                {
                    //Teleport
                    if (Input.GetKey(KeyCode.LeftAlt))
                        HandleTeleport(pos);
                    //Move
                    else
                        HandleMove(pos);
                }
                else
                {
                    
                    //Intercept
                    if (Input.GetKey(KeyCode.LeftControl))
                       HandleIntercept(ent);
                      
                    //Follow
                    else
                        HandleFollow(ent);
                        
                }
            }
            else
            {
                //Whenever right click did not collide
                //Debug.Log("Right mouse button did not collide with anything");
            }
        }
    }


    void AddOrSet(Command c, UnitAI uai)
    {
        if (Input.GetKey(KeyCode.LeftShift))
            uai.AddCommand(c);
        else
            uai.SetCommand(c);
    }

    public void HandleTeleport(Vector3 point)
    {
        Teleport teleport = new Teleport(SelectionMgr.inst.selectedEntity, point);
        UnitAI uai = SelectionMgr.inst.selectedEntity.GetComponent<UnitAI>();
        AddOrSet(teleport, uai);
    }

    public void HandleMove(Vector3 point)
    {
        Move m = new Move(SelectionMgr.inst.selectedEntity, hit.point);
        UnitAI uai = SelectionMgr.inst.selectedEntity.GetComponent<UnitAI>();
        AddOrSet(m, uai);
    }

        
    public void HandleFollow(Entity381 ent)
    {
        Follow f = new Follow(SelectionMgr.inst.selectedEntity, ent, new Vector3(100, 0, 0));
        UnitAI uai = SelectionMgr.inst.selectedEntity.GetComponent<UnitAI>();
        AddOrSet(f, uai);

    }
    
    void HandleIntercept(Entity381 ent)
    {

        Intercept intercept = new Intercept(SelectionMgr.inst.selectedEntity, ent);
        UnitAI uai = SelectionMgr.inst.selectedEntity.GetComponent<UnitAI>();
        AddOrSet(intercept, uai);

    }

    public float clickRadius = 100;
    public Entity381 FindClosestEntInRadius(Vector3 point, float radiusSquared)
    {
        Entity381 minEnt = null;
        float min = float.MaxValue;
        foreach (Entity381 ent in EntityMgr.inst.entities)
        {
            float distanceSqr = (ent.transform.position - point).sqrMagnitude;
            //Check if entity is within the squared radius
            if (distanceSqr < radiusSquared)
            {
                if (distanceSqr < min)
                {
                    minEnt = ent;
                    min = distanceSqr;
                }
            }
        }
        return minEnt;
    }
}
