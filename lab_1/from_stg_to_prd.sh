#!/bin/bash
git checkout prd
git merge --commit dev  -m "Merge stg branch to prd branch"
time_tag=$(date '+%dd-%mm-%YYYY_%H-%M')
git tag
git push origin prd
git push origin "$time_tag"
