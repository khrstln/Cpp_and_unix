#!/bin/bash
git checkout stg
git merge --commit dev  -m "Merge dev branch to stg branch"
time_tag=$(date '+%dd-%mm-%YYYY_%H-%M')
git tag
git push origin stg
git push origin "$time_tag"
