using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Teleport : Command
{
    public Vector3 teleportPosition;

    public Teleport(Entity381 ent, Vector3 pos) : base(ent)
    {
        teleportPosition = pos;
    }

    // Start is called before the first frame update
    public override void Init()
    {
        Debug.Log("Teleporting Entity to " + teleportPosition);
    }

    // Update is called once per frame
    public override void Tick()
    {
        entity.position = teleportPosition;
    }

    public Vector3 diff = Vector3.positiveInfinity;
    public float doneDistanceSq = 10;
    public override bool IsDone()
    {
        diff = teleportPosition - entity.position;
        return (diff.sqrMagnitude < doneDistanceSq);
    }

    public override void Stop()
    {

    }
}
