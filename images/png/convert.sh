for img in *.png; do
    if [ -f "$img" ]; then
        # Remove .png extension and add .xpm extension
        base_name="${img%.*}"
        convert "$img" "${base_name}.xpm"
        echo "Converted $img to ${base_name}.xpm"
    fi
done
