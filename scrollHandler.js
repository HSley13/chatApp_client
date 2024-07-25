document.addEventListener('DOMContentLoaded', function () {
    setTimeout(() => {
        const inputFields = [
            document.querySelector('#inputFieldFirstName'),
            document.querySelector('#inputFieldLastName'),
            document.querySelector('#inputFieldPhoneNumber'),
            document.querySelector('#inputFieldPassword'),
            document.querySelector('#inputFieldPasswordConfirmation')
        ];
        const container = document.querySelector('#screen');

        if (!container) {
            console.error('Container not found');
            return;
        }

        inputFields.forEach(field => {
            if (field) {
                field.addEventListener('focus', () => {
                    setTimeout(() => {
                        const rect = field.getBoundingClientRect();
                        container.style.marginBottom = `${window.innerHeight - rect.bottom}px`;
                    }, 300); // Adjust delay if necessary
                });

                field.addEventListener('blur', () => {
                    container.style.marginBottom = '0px';
                });
            } else {
                console.warn('Field not found');
            }
        });
    }, 1000); // Adjust delay if needed
});
