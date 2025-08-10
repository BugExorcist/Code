using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Camera : MonoBehaviour
{
    [SerializeField] Transform target;
    [SerializeField] Vector3 offset; //和目标的偏移量
    [SerializeField] float transitionSpeed = 2; //过度速度

    private void LateUpdate()
    {
        if (target != null)
        {
            Vector3 targetPos = target.position + offset;
            transform.position = Vector3.Lerp(transform.position, targetPos, transitionSpeed * Time.deltaTime);
        }
    }
}
