using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Intercept : Command
{

    public Entity381 targetEntity;
    public Vector3 predictedPos;
    float distance, relativeSpeed, timeToIntercept;

    public Intercept(Entity381 ent, Entity381 targetedEnt) : base(ent)
    {
        targetEntity = targetedEnt;
    }
    public override void Init()
    {
        entity.desiredSpeed = entity.maxSpeed;
        Debug.Log("Intercepting Entity" + targetEntity.index);

        isRunning = true;
    }



    public override void Tick()
    {

        //calculate time to intercept
        distance = (targetEntity.position - entity.position).magnitude;
        relativeSpeed = (entity.velocity - targetEntity.velocity).magnitude;
        timeToIntercept = distance / relativeSpeed;

        //calculate target's predicted position
        predictedPos = targetEntity.position + (targetEntity.velocity * timeToIntercept);

        //calculate heading
        diff = predictedPos - entity.position;
        entity.desiredHeading = Utils.Degrees360(Mathf.Atan2(diff.x, diff.z) * Mathf.Rad2Deg);

        Debug.DrawLine(entity.position, predictedPos, Color.red);
        Debug.DrawLine(predictedPos, targetEntity.position, Color.red);
    }


    public Vector3 diff = Vector3.positiveInfinity;
    public float doneDistanceSqr = 1000;
    public override bool IsDone()
    {
        //intercept is done when it reaches target's position
        diff = targetEntity.position - entity.position;
        return (diff.sqrMagnitude < doneDistanceSqr);

    }
    public override void Stop()
    {
        Debug.Log("Target Intercepted");
        entity.desiredSpeed = 0;
    }


}