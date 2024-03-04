from typing import List

def findDuplicate(nums: List[int]) -> int:
    red = 0
    blue = 0
    green = 0
    while True:
        red = nums[red]
        blue = nums[nums[blue]]
        if red == blue:
            break
    while True:
        red = nums[red]
        green = nums[green]
        if red == green:
            break
    return red