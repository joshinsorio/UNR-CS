using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Entity381 : MonoBehaviour
{
    public Vector3 position = Vector3.zero;
    public Vector3 velocity = Vector3.zero;
    public GameObject cameraRig;
    public GameObject selectionCircle;
    public bool isSelected;
    public int index;

    public float speed;
    public float desiredSpeed;
    public float heading;
    public float desiredHeading;

    public float acceleration;
    public float turnRate;
    public float maxSpeed;
    public float minSpeed;

    // Start is called before the first frame update
    void Start()
    {

    }

    // Update is called once per frame
    void Update()
    {
        selectionCircle.SetActive(isSelected);
    }
}
